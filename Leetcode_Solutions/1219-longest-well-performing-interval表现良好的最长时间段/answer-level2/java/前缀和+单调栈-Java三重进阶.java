参考了top1的精选题解，再加上自己的理解

1、不使用前缀和+暴力破解

没有使用前缀和，先尝试二分查找搜寻，但是发现不适用查找数组。转而暴力破解，看到其他题解有成功的例子，可是Java计算超出时间限制。用C++等暴力破解有可能成功。

代码：

超出时间限制，算法复杂度太差

96 / 98 个通过测试用例

```java
public int longestWPI(int[] hours) {
    // 先计算得到数组内大于8和其他的统计数
    int daysWPI=0, notDaysWPI=0, length=hours.length;
    for(int i = 0;i<length;i++){
        daysWPI+=((hours[i]>8)?1:0);
        notDaysWPI=length-daysWPI;
    }
    
    // 暴力破解，二重循环计算符合条件的最大数组和输出
    int left=0, right=length-1, longestWPI=0;
    int innerDaysWPI=daysWPI,innerNotDaysWPI=notDaysWPI;
    while(left <= right){
        while (left <= right){
            if((innerDaysWPI-innerNotDaysWPI)>0){
                longestWPI=Math.max((right-left+1),longestWPI);
            }
            if(left==right) break;
            if(hours[left]<=8){
                left++;
                innerNotDaysWPI--;
            }else{
                left++;
                innerDaysWPI--;
            }
        }
        if(hours[right]<=8){
            right--;
            notDaysWPI--;
        }else{
            right--;
            daysWPI--;
        }
        left=0;
        innerDaysWPI=daysWPI;
        innerNotDaysWPI=notDaysWPI;
    }
    return longestWPI;
}
```



2、使用前缀和

以输入样例 hours = [9,9,6,0,6,6,9] 为例，我们将大于 8 小时的一天记为 1 分，小于等于 8 小时的一天记为 −1 分。那么处理后，我们得到 score = [1, 1, -1, -1, -1, -1, 1]，然后我们对得分数组计算前缀和 presum = [0, 1, 2, 1, 0, -1, -2, -1]。题目要求返回表现良好时间段的最大长度，即求最长的一段中，得分 1的个数大于得分 −1 的个数，也就是求 score 数组中最长的一段子数组，其和大于 0，那么也就是找出前缀和数组 presum 中两个索引 i 和 j，使 j - i 最大，且保证 presum[j] - presum[i] 大于 0。



代码：

已经可以通过所有测试用例

```java
public int longestWPI(int[] hours) {
    // 简化数据结构，大于8为1，小于等于为-1
    for (int i = 0; i < hours.length; i++){
        hours [i]=(hours [i]>8)?1:-1;
    }
    // 计算前缀和
    int[] presum=new int [hours.length+1]; presum [0]=0;
    for (int i = 1; i < presum.length; i++){
        presum [i] = presum [i-1]+hours [i-1];
    }
    // 两重暴力破解找出前缀和数组 presum 中两个索引 i 和 j，使 j - i 最大，且保证 presum[j] - presum[i] 大于 0
    int longestWPI=0;
    for (int i = 1; i < presum.length; i++){
        for (int j = 0; j < i; j++){
            if ((presum[i]-presum[j])>0){
                longestWPI=Math.max((i-j),longestWPI);
            }
        }
    }
    return longestWPI;
}
```



3、前缀和+单调栈

这里我们先理解一下什么是单调栈：首先栈是只能栈顶出入元素的数据结构，而单调栈就是栈内元素严格单调递增或者单调递减。实现递减单调栈的方式，每次栈顶元素与要插入的新元素比较，如果栈顶元素大于则取出丢弃。这样不断处理栈顶元素，直到新元素插入栈顶成功。

回到题目，我们就将这道题转化为，求 presum 数组中的一个最长的上坡，可以用单调栈实现。我们维护一个单调栈，其中存储 presum 中的元素索引，栈中索引指向的元素严格单调递减，由 presum 数组求得单调栈为 stack = [0, 5, 6]， 其表示元素为 [0, -1, -2]。然后我们从后往前遍历 presum 数组，与栈顶索引指向元素比较，如果相减结果大于 0，则一直出栈，直到不大于 0为止，然后更新当前最大宽度。

使用递减单调栈，存储题目中“绝对下坡”的元素，后序遍历时每一个栈中元素作为“起点”来计算得到“上坡长度”。处理完所有“绝对下坡”的元素，更新得到“最长的上坡长度”就是题中的最长时间段。单调栈的预处理，相当于把“起点”和“坡顶”之间的部分都忽略掉了。



代码：

加入单调栈降低了时间复杂度

```java
public int longestWPI(int[] hours) {
    // 简化数据结构，大于8为1，小于等于为-1
    for (int i = 0; i < hours.length; i++){
        hours [i]=(hours [i]>8)?1:-1;
    }
    // 计算前缀和
    int[] presum=new int [hours.length+1]; presum [0]=0;
    for (int i = 1; i < presum.length; i++){
        presum [i] = presum [i-1]+hours [i-1];
    }
    // 计算单调栈
    Stack<Integer> stack= new Stack<>();
    for (int i = 0; i < presum.length; i++){
        if (!stack.isEmpty()&&presum[stack.peek()]<=presum[i])
            continue;
        stack.push(i);
    }
    // 根据单调栈后序遍历数组计算最长上坡
    int longestWPI=0;
    for (int i=presum.length -1 ; i >= 0; i--){
        if (presum[i]>presum[stack.peek()]){
            longestWPI=Math.max(longestWPI,i-stack.peek());
            stack.pop();
            i++;
            if (stack.empty()) break;
            continue;
        }
    }
    return longestWPI;
}
```

