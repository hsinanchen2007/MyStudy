class Solution {
   public  int[] dailyTemperatures(int[] T) {
       //题目要求：温 列表长度的范围是 [1, 30000]
        int len = T.length;
        if (len<1 || len >30000 ){
            return null;
        }
        //创建结果数组，数组指针
        int j = 0;
        int[] resultArray = new int[len];
        for (int i = 0; i < len; i++) {
            //若是最后一个元素，直接赋值0
            if (i == len-1){
                resultArray[len -1] = 0;
            }
            //循环取出目标数组元素做对比
            int pivot = T[i];
            for (int k = i+1; k <len; k++) {
                //大于等于，移动指针
                if (pivot>=T[k]){
                    j++;
                }else {
                    //小于结束指针移动，+1是因为j初始值为0，同时结束一个元素的循环遍历
                    resultArray[i] = j+1;
                    break;
                }
            }
            //重新记录下一个元素
            j=0;

        }
        return resultArray;
    }
}