遍历一次数组，遍历的同时判断当前下标是否超过右指针如果超过左右指针同时前移一个，然后结果取最小距离；

```
    public int[] shortestToChar(String s, char c) {
        int left = -1;
        int right = -1;
        int[] result = new int[s.length()];
        for (int i = 0; i < result.length; i++) {
            if(i>right){
                for (int j=i;j<result.length;j++){
                    if(s.charAt(j)==c){
                        left = right;
                        right = j;
                        break;
                    }
                }
            }
            if(left==-1){
                result[i] = Math.abs(right-i);
            }else{
                result[i] = Math.abs(Integer.min(right-i,i-left));
            }
        }
        return result;
    }
```
