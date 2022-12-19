### 解题思路
思路很简单：（1）使用二分法找到target元素。如果没有就返回[-1,-1].
           （2）如果找到了target的一个位置,就从这个位置开始，向两边判断是否等于target.直到找到不等的位置，
               将这两个位置记录下来返回就行了。
![image.png](https://pic.leetcode-cn.com/d9157399c65fdb951bbd8bade8f9ad4361e8d7a3130eba222cebf575c405fe9a-image.png)

### 代码

```java
class Solution {
    public int[] searchRange(int[] nums, int target) {
        int left=0;
        int right=nums.length-1;
        int p=-1;
        int [] res = new int[2];

        while(left<=right)
        {
            int middle=left+(right-left)/2;
            if(nums[middle]==target)
            {
                p=middle;
                break;
            }
            if(nums[middle]<=target)
            {
                left=middle+1;
            }
            else{
                right=middle-1;
            }
        }
        if(p!=-1)
        {
            int i=p;
            int j=p;
            while(i>=0&&nums[i]==target)
            {
                i=i-1;
               
            }
            while(j<=nums.length-1&&nums[j]==target)
            {
                j=j+1;
            }
            res[0]=i+1;
            res[1]=j-1;

        }
        else{
            res[0]=p;
            res[1]=p;
        }

        return res;
    }
}
```