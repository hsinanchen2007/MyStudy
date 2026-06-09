### 解题思路
分治法
1、划分子区间：寻找左右区间最大面积，假设s1,s2==找最大==>s3
2、合并子区间：左区间的点集合和右区间的点集合形成的组合，寻找>=s3的组合，更新s3
3、返回s3

其中第2步可以优化，不然有点偏暴力了，暂时还没想到怎么优化

### 代码

```java
class Solution {
        public int find(int[] height, int l, int r) {
                if (l == r)     return 0;
                if (l+1 == r) return Math.min(height[l], height[r]);

                int mid = (l+r+1) >> 1;
                int area1 = find(height, l, mid);
                int area2 = find(height, mid, r);

                int area3 = Math.max(area1, area2);
                //System.out.println(l+" "+ mid +" "+r);

                for (int i = l; i <= mid; i++) {
                        for (int j = mid+1; j <= r; j++) {
                                int areaTmp = Math.min(height[i], height[j])*(j-i);
                                if (areaTmp > area3) {
                                        area3 = areaTmp;
                                }
                        }
                }
                return area3;
        }
    public int maxArea(int[] height) {
                return find(height, 0, height.length-1);
        }
}
```