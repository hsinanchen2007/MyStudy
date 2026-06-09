```java
    // 直接循环法
    public int binaryGap(int N){
        String binary = Integer.toBinaryString(N);
        int last = 0;
        int offset = 0;
        for (int i = 0; i < binary.length(); i++) {
            if(binary.charAt(i) == '1'){
                //当遇到'1'的时候，对比上一次遇到'1'的i
                //如果当前i-last大于上次的i-last，重新记录i-last
                //每遇到i后重新对last赋值
                offset = i - last > offset ? i - last : offset;
                last = i;
            }
        }
        return offset;
    }

    //循环位运算
    public int binaryGap(int N){
        int offset = -1;
        int max = 0;
        while (N > 0){
            if ((N & 1) == 1){
                max = offset > max ? offset : max;
                offset = 0;
            }
            offset = offset == -1 ? offset : (offset + 1);
            N >>= 1;
        }
    }

```