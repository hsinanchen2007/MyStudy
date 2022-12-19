### 解题思路
采用了官方答案的方法。
### 知识点
**1.**  c++中的reverse函数，格式为reverse（&想要反转的起始元素，&想要反转的最后一个元素+1）。
**2.**  学到了(i+k)%size(nums)。
········作用1：当k要求旋转好几轮时，可通过%将其化简为只旋转1轮。
········作用2：通过(i+k)%,可直接获取元素旋转之后的位置
### 感悟
一题多解，没事多看看别人的解法，真的很大程度上拓宽了自己的思路，nice。
### 代码

```cpp
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        //采用反转
        int length=size(nums);
        k%=size(nums);
        reverse(&nums[0],&nums[length]);
        reverse(&nums[0],&nums[k]);
        reverse(&nums[k],&nums[length]);
        
    }
    void rotate2(vector<int>& nums, int k) {
        //外层循环用来决定向右旋转次数
        for(int i=0;i<k%size(nums);i++){
            int tmp;
            tmp=nums[size(nums)-1];
            for(int j=size(nums)-1;j>0;j--){
                nums[j]=nums[j-1];
            }
            nums[0]=tmp;
        }
    }
    
    void rotate3(vector<int>& nums, int k){
        //采用双数组（这样不满足O（1））
        int* a=new int [size(nums)];
        for(int i=0;i<size(nums);i++){
            a[(i+k)%size(nums)]=nums[i];        
        }
        for(int i=0;i<size(nums);i++){
            nums[i]=a[i];
        }
    }
};
```