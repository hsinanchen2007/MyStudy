### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        //初始化栈
        Stack < Integer > stack = new Stack < > ();
        //初始化存放num2中下一个最大元素对的map
        HashMap < Integer, Integer > map = new HashMap < > ();
        //创建存放比较结果的数组
        // int[] res = new int[nums1.length];

        for (int i=0;i < nums2.length;i++) {
            //同时满足时 执行map 记录
           while (!stack.empty() && nums2[i] > stack.peek()) {
               map.put(stack.pop(),nums2[i]);
           }
           // 循环外 保证便利的num2种的元素 均能完成压栈
           stack.push(nums2[i]);
        }

        while(!stack.isEmpty()) {
            map.put(stack.pop(),-1);
        }


        for (int j = 0; j< nums1.length; j++) {
            nums1[j] = map.get(nums1[j]);
        }   
        return nums1;
    }
}
```