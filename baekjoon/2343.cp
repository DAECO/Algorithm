#include <cstdio>
int a[100000];
int n,m;
int count(int len) {
    int cnt = 0;
    int sum = 0;
    for (int i=0; i<n; i++) {
        if (sum + a[i] > len) {
            cnt += 1;
            sum = a[i]; 
        } else {
            sum += a[i];
        }
    }
    return cnt+1;
}
int main() {
    scanf("%d %d",&n,&m);
    int sum = 0;
    for (int i=0; i<n; i++) {
        scanf("%d",&a[i]);
        sum += a[i];
    }
    int left = 1;
    int right = sum;
    int ans = right;
    while (left <= right) {
        int mid = (left+right)/2;
        if (count(mid) <= m) {
            if (ans > mid) {
                ans = mid;
            }
                right = mid-1;
        } else {
            left = mid+1;
        }
    }
    printf("%d\n",ans);
}