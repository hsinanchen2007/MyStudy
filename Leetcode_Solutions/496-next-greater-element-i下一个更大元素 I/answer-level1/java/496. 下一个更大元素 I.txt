
/**
 * Project:
 * Author : zhaozhen
 * Email  :
 * Date   : 2019/9/18
 *
 * 解题思路1: 使用双重循环建立当前值对应的下一个最大值的hash映射 后遍历nums1
 *
 * 解题思路2: 使用单调栈建立当前值对应的下一个最大值的hash映射 后遍历nums1
 * 1.先遍历大数组nums2，首先将第一个元素入栈；
 * 2.继续遍历，当前元素小于栈顶元素时，继续将它入栈；当当前元素大于栈顶元素时，栈顶元素出栈，此时应将该出栈的元素与当前元素形成key-value键值对，存入HashMap中；
 * 3.当遍历完nums2后，得到nums2中元素所对应的下一个更大元素的hash表；
 *
 */
```
public int[] nextGreaterElement(int[] nums1, int[] nums2) {

    //int[] nums2_index = new int[nums2.length];
    int[] res = new int[nums1.length];
    boolean is = false;
    HashMap<Integer , Integer> hashMap = new HashMap<>();
    //建立next max index hash 索引
    for(int i = 0;i < nums2.length;i++){
        is = false;
        for(int j = i+1;j < nums2.length;j++){
            if(nums2[i] < nums2[j]){
                is = true;
                //nums2_index[i] = nums2[j];
                hashMap.put(nums2[i],nums2[j]);
                break;
            }
        }
        if(is == false){
            //nums2_index[i] = nums2[i];
            hashMap.put(nums2[i],nums2[i]);
        }
    }

    for(int i = 0;i < nums1.length;i++){
        if(hashMap.get(nums1[i]) == nums1[i]){
            res[i] = -1;
        }else{
            res[i] = hashMap.get(nums1[i]);
        }
    }

    return res;

}


public int[] nextGreaterElement2(int[] nums1, int[] nums2){

    int[] res = new int[nums1.length];
    Stack<Integer> stack = new Stack<>();
    HashMap<Integer , Integer> hashMap = new HashMap<>();
    //建立next max index hash 索引
    for(int i = 0;i < nums2.length;i++){
        if(stack.isEmpty()){
            stack.push(nums2[i]);
        }else{
            while(!stack.isEmpty() && stack.peek() < nums2[i]){
                int top = stack.pop();
                hashMap.put(top,nums2[i]);
            }
            stack.push(nums2[i]);
        }
    }
    while(!stack.isEmpty()){
        int t = stack.pop();
        hashMap.put(t,t);
    }

    for(int i = 0;i < nums1.length;i++){
        if(hashMap.get(nums1[i]) == nums1[i]){
            res[i] = -1;
        }else{
            res[i] = hashMap.get(nums1[i]);
        }
    }

    return res;


}
```