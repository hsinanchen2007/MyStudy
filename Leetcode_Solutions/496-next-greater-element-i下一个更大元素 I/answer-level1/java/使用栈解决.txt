### 解题思路
方法比较笨；
从头遍历nums1[]，从尾部遍历nums2[]，把nums2[]的元素放入栈中
如果找到与num1[i]一样的元素nums2的元素停止入栈，开始出栈，找到第一个比num1的元素，就break；
如果栈为空了，nums[i]没有变化，那么就赋值-1；

### 代码

```java
class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
    Stack<Integer> stack;
            int temp = 0;
            for(int i=0;i<nums1.length;i++){
                int num=nums1[i];
                stack=new Stack<>();
                for(int j= nums2.length-1;j>=0;j--){
                    stack.push(nums2[j]);//将nums2的元素入栈

                    if(num==nums2[j]){ //找到与nums1一样的元素了
                        while (!stack.isEmpty()){
                            temp=stack.pop();  //出栈，找到大于num的，则赋值，跳出循环
                            if(temp>num) {nums1[i]=temp;break;}
                        }
                        if(stack.isEmpty()&&nums1[i]==num) nums1[i]=-1;//如果栈为空，并且nums[i]的值没变，则赋值-1；
                        break;
                    }
                }
            }
            return nums1;
    }
}
```欢迎讨论。