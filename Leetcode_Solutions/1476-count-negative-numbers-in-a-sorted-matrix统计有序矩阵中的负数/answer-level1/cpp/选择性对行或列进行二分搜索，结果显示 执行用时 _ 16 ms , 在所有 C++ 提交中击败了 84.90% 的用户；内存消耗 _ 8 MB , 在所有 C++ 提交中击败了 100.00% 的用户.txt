```
public:
    //时间复杂度：O(min(nlogm,mlogn))
    //空间复杂度：O(1)
    int countNegatives(vector<vector<int>>& grid) {
        //行数大于列数则对每一列进行二分搜索
        //列数大于行数则对每一行进行二分搜索
        //这样做可以降低时间复杂度至O(min(nlogm,mlogn))
        int maxLen = max(grid.size(),grid[0].size());
        int minLen = min(grid.size(),grid[0].size());
        //合法性判断
        if(!minLen){
            return 0;
        }
        int left,right,mid,i,sum = 0;
        if(maxLen == grid.size()){//对列进行二分搜索
            for(i=0;i<minLen;i++){
                left = 0;
                right = maxLen;
                while(left<right){
                    mid = left+(right-left)/2;
                    if(grid[mid][i] < 0){//小于0满足条件
                        right = mid;
                    }else{//大于等于0都往右边搜索
                        left = mid + 1;
                    }
                }
                //统计负数的数量
                if((left != maxLen) &&  (grid[left][i] < 0)){
                    sum += (maxLen-left);
                }
            }
        }else{//对行进行二分搜索
            for(i=0;i<minLen;i++){
                left = 0;
                right = maxLen;
                while(left<right){
                    mid = left+(right-left)/2;
                    if(grid[i][mid] < 0){//小于0满足条件
                        right = mid;
                    }else{//大于等于0都往右边搜索
                        left = mid + 1;
                    }
                }
                //统计负数的数量
                if((left != maxLen) &&  (grid[i][left] < 0)){
                    sum += (maxLen-left);
                }
            }
        }
        return sum;
    }
};
```
