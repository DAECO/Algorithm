#include <cstdio>
int n,m;
int a[1001][1001];
bool c[1001];
int main() {
    scanf("%d %d",&n,&m);
    for (int i=0; i<m; i++) {
        int x,y,z;
        scanf("%d %d %d",&x,&y,&z);
        a[x][y] = z;
        a[y][x] = z;
    }
    c[1] = true;
    int ans=0;
    for (int k=0; k<n-1; k++) {
        int min = -1;
        int minp;
        for (int i=1; i<=n; i++) {
            for(int j=1; j<=n;j++) {
                if(a[i][j] && c[i] &&!c[j] ){
                    if (min == -1) {
                        min = a[i][j];
                        minp = j;
                    } else if(min > a[i][j]) {
                        min = a[i][j];
                        minp= j;
                    }
                }
            }
        }
        ans += min;
        c[minp] = true;
    }
    printf("%d\n",ans);
    return 0;
}