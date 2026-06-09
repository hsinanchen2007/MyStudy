给出2种都能通过的算法。

先抛出一个O(nlogn)的做法：
首先不删除数的很简单， 不赘述了。
删除数的话又能选到最大区间的一定满足：
1. 删除的一定是负数且为区间内最小的（否则删它干啥);
2. 删除的数一定不在选定区间的两端（否则可以选择较小的区间，且还有删数的权利。

那么针对这两条， 每次如果确定了删除的数， 数组被分成两部分。那么只要针对这两部分求出**左边那一段的最大后缀和** 和 **右边那一段的最大前缀和** 就可以了。然而这两个涉及到区间最大/最小，在我看来至少得用O(logn)时间。

例如：
数组[3,7,2,-2,-5,3,-4,1,-3], 如果考虑删去中间的-5, 则只需要找出[3,7,2,-2]的最大后缀和以及[3,-4,1,-3]的最大前缀和即可。使用倍增数组即可用每次O(logn)时间内做到。

附上C++代码
`class Solution {
public:
    
    int *subsum;
    int **maxPow;
    int **minPow;
    const int maxp = 18;
    
    int findMax(int **maxPow, int x, int y){
        int cur = x;
        int ans = maxPow[x][0];
        int p = maxp - 1;
        while(p >= 0 && cur <= y){
            int last = cur + (1 << p) - 1;
            if(last <= y){
                //printf("%d %d %d %d %d\n",x,y,cur,p,maxPow[cur][p]);
                ans = max(ans, maxPow[cur][p]);
                cur = last + 1;
            }
            p--;
        }
        
        return ans;
    }
    
     int findMin(int **minPow, int x, int y){
        int cur = x;
        int ans = minPow[x][0];
        int p = maxp - 1;
        while(p >= 0 && cur <= y){
            int last = cur + (1 << p) - 1;
            if(last <= y){
                ans = min(ans, minPow[cur][p]);
                cur = last + 1;
            }
            p--;
        }
        
        return ans;
    }
    
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        
        subsum = (int *)malloc(sizeof(int) * (n+1));
        
        subsum[0] = 0;
        int maxv = arr[0], minv = arr[0];
        for(int i=0; i<n; i++){
            subsum[i+1] = subsum[i] + arr[i];
            if(arr[i] > maxv)maxv = arr[i];
            if(arr[i] < minv)minv = arr[i];
        }
        
        if(maxv <= 0)return maxv;
        if(minv >= 0)return subsum[n];
        
 
        
        maxPow = (int **)malloc(sizeof(int *) * (n+1));
        minPow = (int **)malloc(sizeof(int *) * (n+1));
        for(int i=0; i<=n; i++){
            maxPow[i] = (int *)malloc(sizeof(int) * maxp);
            minPow[i] = (int *)malloc(sizeof(int) * maxp);
            maxPow[i][0] = minPow[i][0] = subsum[i];
        }
        
        for(int p=1; p<maxp; p++){
            int length = 1<<p;
            if(length > n+1)break;
            for(int i=0; i<=n; i++){
                int j = i + length - 1;
                if(j > n)break;
                
                int k = i + (1 << (p-1));
                maxPow[i][p] = max(maxPow[i][p-1], maxPow[k][p-1]);
                minPow[i][p] = min(minPow[i][p-1], minPow[k][p-1]);
            }
        }
        
        int ans = maxv;
        
        for(int i=0; i<n; i++){            
            if(arr[i] < 0){
                int bIndex = i+1;

                int min_left = findMin(minPow, 0, bIndex-1);
                int max_right = findMax(maxPow, bIndex, n);
                
                int cur = (max_right - subsum[bIndex]) + (subsum[bIndex - 1] - min_left);
                if(cur > ans)ans = cur;
                
                
            }
        }
        
        
        return ans;
    }
};`

其实也有O(n)做法， 加一个后缀和数组（不是后缀数组）， 然后加一个记录最小前缀和和后缀和的数组即可O(n), 注意细节即可
class Solution {
public:
    
    int *prefixsum;
    int *suffixsum;
    int *prefixmin;
    int *suffixmin;
    
    
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        
        prefixsum = (int *)malloc(sizeof(int) * (n+1));
        suffixsum = (int *)malloc(sizeof(int) * (n+1));
        prefixmin = (int *)malloc(sizeof(int) * (n+1));
        suffixmin = (int *)malloc(sizeof(int) * (n+1));
        
        
        prefixsum[0] = prefixmin[0] = 0;
        suffixsum[n] = suffixmin[n] = 0;
        
        int maxv = arr[0], minv = arr[0];
        for(int i=0; i<n; i++){
            prefixsum[i+1] = prefixsum[i] + arr[i];
            prefixmin[i+1] = min(prefixmin[i],prefixsum[i+1]);
            
            if(arr[i] > maxv)maxv = arr[i];
            if(arr[i] < minv)minv = arr[i];
        }
        
        for(int i=n-1; i>=0; i--){
            suffixsum[i] = suffixsum[i+1] + arr[i];
            suffixmin[i] = min(suffixmin[i+1], suffixsum[i]);
        }
        
        if(maxv <= 0)return maxv;
        if(minv >= 0)return prefixsum[n];
        
       /* for(int i=0; i<=n; i++){
            printf("%d %d %d %d %d\n",i,prefixsum[i],prefixmin[i],suffixsum[i],suffixmin[i]);
        }*/
        
        int ans = maxv;
        
        for(int i=0; i<n; i++){            
            if(arr[i] < 0){
                int bIndex = i+1;
                int max_left = 0, max_right = 0;

                if(i > 0) max_left = prefixsum[bIndex - 1] - prefixmin[bIndex - 1];
                max_right = suffixsum[bIndex] - suffixmin[bIndex];
                
                //printf("%d %d %d\n", i, max_left, max_right);
                
                int cur = max_left + max_right;
                if(cur > ans)ans = cur;
                
                
            }
        }
        
        
        return ans;
    }
};