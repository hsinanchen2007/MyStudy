### 解题思路
采用分治法来解决逆序对问题。
将输入序列A分为两部分，AL和AR。AL和AR可以使用完全相同的策略用于AL和AR中的逆序对数。
原问题的解也有可能在AL和AR中，所以要考虑跨界的可能。
因此总的逆序对数等于左边子问题的AL加上右边子问题的AR的逆序对数，再加上跨界情况求得的逆序数。
$$T(n) = 2T(n/2)+O(n) = O(nlogn)$$
				
![image.png](https://pic.leetcode-cn.com/e5f2c52005662384c82159d9203a0a17d9152cf84fde4b6c49117d6b7343031f-image.png)

### 代码

```cpp
class Solution {
public:
    //int merge_and_count(int l,int middle,int r,vector<int>& num);
    int count_inversions_dc(int l,int r,vector<int>& num){
        if(l>=r){
            return 0;
        }
        int middle = (r+l)/2;
        int countLA = count_inversions_dc(l,middle,num);
        int countRA = count_inversions_dc(middle+1,r,num);
        int countLRA = merge_and_count(l,middle,r,num);
        
        return countLA+countRA+countLRA;
}
    int merge_and_count(int l,int middle,int r,vector<int>& num){
        int i=l,j=middle+1,k=0,res=0;
        int *temp = new int[r-l+1];//临时数组,临时存放比较后的数字
        while(i<=middle && j<=r){//此过程类似合并排序
            if(num[i] <= num[j]){//加了等号 则顺利通过  可能由于相等的数字不算逆序对
                temp[k++] = num[i++];
            }
            else{
                temp[k++] = num[j++];
                res = res +(middle-i+1);//统计左半边能和右半边该元素构成的逆序对数
            }
        }
        //极端情况特殊处理 
        while(i<=middle){
                temp[k++]=num[i++];
        }
        while(j<=r){
                temp[k++]=num[j++];
        }
        for(int i=0;i<k;i++){
                num[l+i] = temp[i];
        }
        return res;
    }
    int reversePairs(vector<int>& nums) {
        return count_inversions_dc(0,nums.size()-1,nums);
    }
};
```