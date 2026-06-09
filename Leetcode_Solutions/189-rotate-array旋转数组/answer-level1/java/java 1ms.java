# 思路
    从起始位置一直向右移动，有两种可能，第一种：跳了几步就回到起始位置，比如{1,2,3,4,5,6} 2；第二种：所有元素都移动过下一个指针指向已经移动过的元素。开始我还想着怎么给移动过的元素做个标记，后来想想移动次数不就是数组的长度嘛，直接可以定义个count变量来控制循环。
# 代码
```
public void rotate(int[] nums, int k){
        if(nums.length == 0||nums.length == 1) return;
        int realMove = k%nums.length;       //realMove为实际向右移动的大小
        if(realMove == 0) return;
        //i为移动元素的指针，temp1为起始值，temp2为移动后此位置的值，count为移动次数
        int i = 0,temp1 = 0,temp2,count = 0,length = nums.length;
        for(int j = 0;j<length;j++){
            i = j;
            temp1 = nums[i];
            if(count == length) break;      //如果移动次数为length说明所有元素移动完成
            //移动元素
            do{
                temp2 = nums[(i+realMove)%length];
                nums[(i+realMove)%length] = temp1;
                temp1 = temp2;
                i = (i+realMove)%length;
                count++;
            }while(j != i);     //从起始位置一直右移直到回到起始位置开始下一轮for循环
        }
        return;
    }
```
