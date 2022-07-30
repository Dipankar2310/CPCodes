vector<int> seive(int n){
    vector<int>v(n+1);
    v[0]=1,v[1]=1;
    for(int i=2;i<=n;i++){
        if(v[i]==0){
            for(int j=i*i;j<=n;j+=i ){
                v[j]=1;
            }
        }
    }
    return v;
}
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
// Difference array D[i] of a given array A[i] is defined as D[i] = A[i]-A[i-1] (for 0 < i < N ) and D[0] = A[0] considering 0 based indexing. 
// Difference array can be used to perform range update queries “l r x” where l is left index, r is right index and x is value to be added and after all 
// queries you can return original array from it. Where update range operations can be performed in O(1) complexity.

// update(l, r, x) : Add x to D[l] and subtract it from D[r+1], i.e., we do D[l] += x, D[r+1] -= x
// printArray() : Do A[0] = D[0] and print it. For rest of the elements, do A[i] = A[i-1] + D[i] and print them.
// Time complexity of update here is improved to O(1). Note that printArray() still takes O(n) time. 
 

// Creates a diff array D[] for A[] and returns
// it after filling initial values.
vector<int> initializeDiffArray(vector<int>& A)
{
    int n = A.size();
 
    // We use one extra space because
    // update(l, r, x) updates D[r+1]
    vector<int> D(n + 1);
 
    D[0] = A[0], D[n] = 0;
    for (int i = 1; i < n; i++)
        D[i] = A[i] - A[i - 1];
    return D;
}
// Does range update
void update(vector<int>& D, int l, int r, int x)
{
    D[l] += x;
    D[r + 1] -= x;
}
 
// Prints updated Array
int printArray(vector<int>& A, vector<int>& D)
{
    for (int i = 0; i < A.size(); i++) {
        if (i == 0)
            A[i] = D[i];
 
        // Note that A[0] or D[0] decides
        // values of rest of the elements.
        else
            A[i] = D[i] + A[i - 1];
 
        cout << A[i] << " ";
    }
    cout << endl;
}
//KADANE
int maxSubArraySum(int a[], int size)
{
    int max_so_far = INT_MIN, max_ending_here = 0;
 
    for (int i = 0; i < size; i++)
    {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
 
        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}