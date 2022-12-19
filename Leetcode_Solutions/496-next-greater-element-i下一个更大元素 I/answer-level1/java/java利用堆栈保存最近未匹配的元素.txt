### 解题思路
先忽略nums1,我们先找出nums2中所有元素的下一个更大的值
构造一个hashMap,key值为nums2的每一个元素值，value值为下一个更大的值
同时构造一个堆栈，用于保存从左往右依次未匹配的元素。然后每次来新的一个数，都循环判断新的数是否比堆栈的顶部元素大
以[1,3,2,4]为例
首先是1
看堆栈里有元素,没有先把1压入进来。
其次是3
这时候3比1大，那么将(1->3)保存到hashMap,
同时将3压入堆栈
再进入2,这时候2比3小，所以将2也压入堆栈
最后是4,
这时候2,3都比4小，所以将(2->4),(3->4)都放入到map,同时压入4
这时候循环结束,4没有匹配的，所以4->-1

### 代码

```java
class Solution {
    

    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        //先对nums2构建一个map,map的key为nums2的元素值,value为比它大的下一个元素值
        //同时将当前数存入到堆栈中
        Map<Integer,Integer> hashMap = new HashMap<>();
        Stack<Integer> unMatchedStack = new Stack<Integer>();
        for(int num:nums2){
            if(!unMatchedStack.empty()){
                Integer peekNum = unMatchedStack.peek();
                while(num>peekNum){
                    hashMap.put(peekNum,num);
                    unMatchedStack.pop();
                    if(unMatchedStack.isEmpty()){
                        break;
                    }
                    peekNum = unMatchedStack.peek();
                }
            }
            unMatchedStack.push(num);
        }
        while(!unMatchedStack.empty()){
            Integer num = unMatchedStack.pop();
            hashMap.put(num,-1);
        }
        int[] result = new int[nums1.length];
        for(int i=0;i<nums1.length;i++){
            result[i] = hashMap.get(nums1[i]);
        }
        return result;
    }

}
```