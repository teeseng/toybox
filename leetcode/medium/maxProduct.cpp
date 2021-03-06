#include <iostream>
#include <vector>
using namespace std;

int maxProduct(vector<int>&);
int maxProductDP(vector<int>&);

// maximum product array
int main() {
    vector<int> t1 = {3,-1,4,2};
    vector<int> t2 = {0,2,0,2,7,1,-1,-9,1};
    cout << maxProduct(t1) << " expected 8 " << endl;
    cout << maxProductDP(t2) << " expected 126 " << endl;
    return 0;
}

// 2-ptr starting from front and back
int maxProduct(vector<int>& A) {
    int n = A.size();
    int global = 1;
    int front = 1;
    int back = 1;
    for(int i = 0; i < n; i++) {
       front *= A[i];
       back *= A[n - i - 1];
       global = max(global, max(front,back));
       front = front == 0 ? 1 : front;
       back = back == 0 ? 1 : back;
    }
    return global;
}

// DP version, one iterations
int maxProductDP(vector<int>& A) {
    int n = A.size();
    int* minlist = new int[n];
    int* maxlist = new int[n];
    minlist[0] = A[0];
    maxlist[0] = A[0];
    int res = A[0];
    for(int i = 1; i < n; i++) {
        minlist[i] = min(A[i], min(minlist[i-1] * A[i], maxlist[i - 1] * A[i]));
        maxlist[i] = max(A[i], max(minlist[i-1] * A[i], maxlist[i - 1] * A[i]));
        res = max(res, maxlist[i]);
    }
    return res;
}


