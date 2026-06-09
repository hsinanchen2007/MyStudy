```
        int[] result = new int[2];
        //0为分子，1为分母
        result[0] = 1;
        result[1] = cont[cont.length - 1];
        for (int i = cont.length - 2; i >= 0; i--) {
            //分数相加
            int temp = cont[i];
            temp *= result[1];
            result[0] += temp;
            //分数颠倒
            temp = result[0];
            result[0] = result[1];
            result[1] = temp;

        }
        int temp = result[0];
        result[0] = result[1];
        result[1] = temp;
        return result;
```
1. 首先初始化一个长度为2的结果数组，将第一位作为分子，第二位作为分母
2. 从倒数第二个数开始遍历，把该数乘上分母加到分子上去
3. 把分子分母颠倒
4. 返回结果