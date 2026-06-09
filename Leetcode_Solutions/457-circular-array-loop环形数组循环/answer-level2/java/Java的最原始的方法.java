>比较简单,比较原始

```
public boolean circularArrayLoop(int[] nums) {
        boolean flag = false;
        for (int i = 0, length = nums.length; i < length; i++) {
            int preValue = nums[i];//这也是index移动的值
            if (Math.abs(preValue) == length)//判断移动的值是否为数组的长度,即避免循环
                continue;
//这个三目运算符的意思是看看最终的index是否为负,因为java中被除数如果为负,那么余数也为负,在数组中需要把正和负单独拎出来处理,outer的意思仅仅是和while循环里的做区分
            int outerIndex = (i + preValue) < 0 ? (i + preValue) % length + length : (i + preValue) % length;
            int nowValue = nums[outerIndex];//记录下一个index的值
            int index = outerIndex;//这个值是要和i进行对比
            int count = 0;//这个值是为了能够跳出循环
            //三个条件①跳动的方向要一致②index一致③循环的次数不能超过length
            while (preValue * nowValue > 0 && index != i && count < length) {
                count++;
//迭代式的进行操作,基本上和第一次的处理差不多,可能有一点细节不同
                preValue = nowValue;
                if (Math.abs(preValue) == length)
                    continue;
                int innerIndex = (index + preValue) < 0 ? (index + preValue) % length + length : (index + preValue) % length;
                nowValue = nums[innerIndex];
                if (Math.abs(nowValue) == length)
                    continue;
                index = innerIndex;
                if (index % length == i){
                    flag = true;
                    break;
                }
            }
        }
        return flag;
    }
```
