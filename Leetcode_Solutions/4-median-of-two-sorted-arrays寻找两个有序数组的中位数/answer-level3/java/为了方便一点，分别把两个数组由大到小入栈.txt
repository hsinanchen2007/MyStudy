### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        // 有一个数组为空
        if(nums1.length == 0){
            return findMid(nums2);
        } 
        if(nums2.length == 0){
            return findMid(nums1);
        }

        // 两个数组都不为空
        return findMid(nums1, nums2);

    }

    double findMid(int[] arr){
        if(arr.length % 2 == 0){
            return (arr[arr.length/2 - 1] + arr[arr.length/2])/2.0;
        } else {
            return arr[arr.length/2];
        }
    }

    double findMid(int[] arr1, int[] arr2){
        // 两个数组的总长度
        int length = arr1.length + arr2.length; 

        // 把两个数组放到两个栈中，为了便于操作，其实不用栈的话可以达成更快的结果
        LinkedList<Integer> stack1 = new LinkedList<>();
        for(int i = arr1.length - 1; i >=0; i--){
            stack1.push(arr1[i]);
        }
        LinkedList<Integer> stack2 = new LinkedList<>();
        for(int i = arr2.length - 1; i >=0; i--){
            stack2.push(arr2[i]);
        }

        // 实际上就是找到两个数组的总长度中，中间的两个数即可
        // 如果总长度是奇数，取第2个数，如果总长度是偶数，那么就取这两个数的中位数即可
        int[] r = new int[2];
        int index = -1;
        while(true){
            index++;
            // 这里每次两个栈中栈顶较小的数弹出
            int min = getMin(stack1,stack2);
            if(index == length/2 - 1){  // 找到第length/2 - 1的数
                r[0] = min;
            }
            if(index == length/2){   //找到第length/2的数后，就不用再遍历了
                r[1] = min;
                break;
            }   
        }
        if(length%2 == 0){
            return (r[0] + r[1])/2.0;
        }
        return r[1];
    }

    // 每次只需要比较两个栈的栈顶元素，弹出较小的即可
    public int getMin(LinkedList<Integer> stack1, LinkedList<Integer> stack2){
        if(stack1.isEmpty()){
            return stack2.pop();
        }
        if(stack2.isEmpty()){
            return stack1.pop();
        }
        int s1 = stack1.peek();
        int s2 = stack2.peek();
        
        return s1 < s2 ? stack1.pop() : stack2.pop();
    }
}
```