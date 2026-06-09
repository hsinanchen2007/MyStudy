和荷兰旗一个逻辑，维护三个指针，一个偶数应该插入的位置，一个指向奇数应该插入的位置，一个用来遍历数组。遍历时候遇到偶数和偶数指针交换数据，遇到奇数和指向奇数的指针交换数据，这里注意和偶数指针交换之后，两个指针都要加一，和基数指针交换数据之后，奇数指针减一，遍历的指针不动。这是因为偶数指向的那个数，之前已经遍历到了交换完不需要再次遍历，所以加一。而奇数指针指向的那个数之前还没有遍历过，所以遍历指针不能加一。下边是代码：
```
class Solution {
    public int[] sortArrayByParity(int[] A) {
        int l = 0;
        int r = A.length-1;
        int index = 0;
        while(index <= r)
        {
            if(A[index]%2 == 0)
            {
                swap(A,l,index);
                index++;
                l++;
            }
            else
            {
                swap(A,r,index);
                r--;
            }
        }
        return A;
    }
    
    public void swap(int[] nums,int i,int j)
    {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}
```
75题颜色分类，同样的思路
https://leetcode-cn.com/problems/sort-colors/