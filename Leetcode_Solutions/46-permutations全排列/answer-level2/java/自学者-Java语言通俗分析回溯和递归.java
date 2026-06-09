### 解题思路
* 官方解题带太多参数形成理解上的费解，进行适当精简和参数命名优化
* 算法的本质是复杂问题变换为子问题
示例：
输入nums=[1,2,3]
全排列描述
选择1时：1放在0的位置，剩下的数字进行了全排列
1,2,3
1,3,2
选择2时：2放在0的位置，剩下的数字进行了全排列
2,1,3
2,3,1
选择3时：3放在0的位置，剩下的数字进行了全排列
3,1,2
3,2,1
也就是当输入nums=[1,2,3]时
（1）一定有一个遍历出现
```java
for(int i = 0; i <= 2 i++) {
    
}
```
（2）当每个数处在0的位置上，剩余元素就要进行一次全排列，这时形成一个递归
```java
//---------step1.
for(int i = 0; i <= 2 i++) {
    //第1个数放在0的位置
    swap(nums,0,0);
    //全排列剩余nums[^,2,3],数组坐标从1到2
    perm(num,1,2);
    swap(nums,0,0);//第一步先不理解这个，（全排列子列表以后，将位置还原，选第一个数时原地不变。）
}
//---------step2.
for(int i = 0; i <= 2 i++) {
    //第2个数放在0的位置，形成nums[2,1,3]
    swap(nums,0,1);
    //将2移动到0的位置，1被移动到2的位置，全排列剩余1和3，形成nums[^,1,3],因为1此时在0的位置上，所以全排列之前要在step1时将数字换回来
    perm(num,1,2);
    swap(nums,0,1); //全排列子列表以后，将位置还原[2,1,3]->[1,2,3]
}
//---------step3.
for(int i = 0; i <= 2 i++) {
    //第3个数放在0的位置
    swap(nums,0,2);
    //全排列剩余nums[^,1,2],数组坐标从1到2
    perm(num,1,2);
    swap(nums,0,2); //全排列子列表以后，将位置还原[3,1,2]->[2,1,3]
}
```
其他技巧：
1.交换元素采用List<Integer>，可以善用API完成数据交换：
Collections.swap(list,i,j);
2.在一个固定数组中通过下标控制某个位置，认为是0的位置非常难以理解，其形式i=from是比较难以理解的
如果进行数组裁剪，就更加清楚了，此处优化参数命名from,to，其中from代表的是第一个元素，这就是为什么官方题解命名为first的原因。

### 代码

```java
class Solution {
    private List<List<Integer>> output = new LinkedList<>();
    public List<List<Integer>> permute(int[] nums) {
        List<Integer> numList = Arrays.stream(nums).boxed().collect(Collectors.toList());
        //全排列0～n-1的所有元素
        perm(numList,nums.length,0);
        return output;
    }
    
    private void perm(List<Integer> nums,int len,int from) {
        //通过from来判断是否结束当前的遍历
        if(from == len) {
            output.add(new ArrayList(nums));
        }
        //一定是明确数组的下标从哪个元素到哪个元素结束
        for(int i = from; i <= len - 1; i++) {
            //把第0个元素和当前选定元素进行交换
            //每个全排列的第一个位置是from，所有元素都要跟第一个元素进行交换
            //第0个元素和0交换就是保持不变。
            Collections.swap(nums,from,i);
            
            perm(nums,len,from+1);
            
            //为了避免出现重复，全排列之后要把顺序还原到最初
            Collections.swap(nums,from,i);
            
        }
    }

}
```