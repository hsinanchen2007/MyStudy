```
 /** 这个题简单理解就是排序
        1.利用三指针; 一个指针left指向需要替换的0， 一个right指向2， 一个p从左向右扫一遍
        2.p=0,移到左边和left交换； p=1跳过;  p=2移到右边和right交换
        
        ↓
        ↓                 ↓
        0  2  0  1  1  2  2
*/

    void sortColors(vector<int>& nums) {
        if (nums.size() <=1) return;

        int size = nums.size();
        int leftIndex = 0, rightIndex = size-1;
        int pIndex = 0;
         
        while(pIndex <= rightIndex) {
            int p_v = nums[pIndex];

            if (p_v == 0) {
                sort(nums,leftIndex++,pIndex++);  // 交换后left++， p还要判断（不动）
            }else if (p_v == 1) { 
                pIndex++;
            }else { // 2
                sort(nums,pIndex,rightIndex--);  // 交换后left++， p还要判断（不动）
            }
        }
    }

    void sort(vector<int>& nums, int aIndex,int bIndex) {
        int temp = nums[aIndex];
        nums[aIndex] = nums[bIndex];
        nums[bIndex] = temp;
    }
```
