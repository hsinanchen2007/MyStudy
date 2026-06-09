```
class Solution {
public:
    // 二分法
    // 基本思路  比较mid元素和左右的大小，情况1：如果比右边大，那么最小值在mid的右面
    // 情况2：如果比左边小比右边小，那么在mid的左面(或者该数字就是最小值)
    // 情况3：比左边大比右边小，mid的左面
    // 情况4：比左边小比右边大，不可能
    // 注：特殊情况特殊对待

    int minArray(vector<int>& numbers) {
        int len = numbers.size();
        int left = 0, right = len-1;
        int mid = (left+right)/2;
        while(left<=right){
            if(numbers[mid]<=numbers[left] && numbers[mid]<=numbers[right]){ // 情况2
                if(mid==left||numbers[mid]<numbers[mid-1]){
                    // 小于一定是
                    return numbers[mid];
                }
                //else if(numbers[mid]==numbers[left] && numbers[mid]==numbers[right]){
                //    return numbers[mid];
                //}
                else if(numbers[mid]==numbers[left]||numbers[mid]==numbers[right]){
                    int min = numbers[left];
                    for(int i=left+1; i<=right; ++i){
                        if(numbers[i]<min)
                            min = numbers[i];
                    }
                    return min;
                }
                else {
                    right = mid - 1;
                }
            }
            else if(numbers[mid]>numbers[right]){ // 只要右面大那么一定在mid的右面
                left = mid+1;
            }
            else{ 
                right = mid-1;
            }
            mid = (left+right)/2;
        }
        return -1;
    }
};
```
