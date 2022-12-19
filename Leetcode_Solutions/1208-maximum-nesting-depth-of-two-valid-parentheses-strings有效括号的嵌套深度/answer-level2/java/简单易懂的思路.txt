思路：
①当左括号来得时候 看当前A与B字符串中，谁剩余的左括号少，放入少的一方
②当右括号来得时候，看当前A与B字符串，谁拥有左括号，就给谁
```
    public int[] maxDepthAfterSplit(String seq) {

        char[] chars = seq.toCharArray();
        int bLeftNum = 0;
        int aLeftNum = 0;

        int[] a = new int[chars.length];
        for(int i = 0; i < chars.length; i++){
            char tempChar = chars[i];
            if(tempChar == ')'){//如果是有括号
                if(aLeftNum == 0){//如果等于这个 说明这个右括号 必须放到 B字符串中 与下面 if(aLeftNum >= bLeftNum)对应
                    a[i] = 0;
                    bLeftNum--;
                } else {
                    a[i] = 1;
                    aLeftNum--;
                }
            } else {
                if(aLeftNum >= bLeftNum){
                    a[i] = 0;
                    bLeftNum++;
                } else {
                    a[i] = 1;
                    aLeftNum++;
                }
            }
        }
        return a;
    }
```
