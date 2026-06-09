不是简单的方法，但是也出来了，看到大佬的方法真想一巴掌拍死自己，我tm怎么那么菜
```
public int hammingDistance(int x, int y) {
        String strX = Integer.toBinaryString(x);
        String strY = Integer.toBinaryString(y);
        while (strX.length() < strY.length()){
            strX = "0" + strX;
        }
        while (strX.length() > strY.length()){
            strY = "0" + strY;
        }
        char[] charsX = strX.toCharArray();
        char[] charsY = strY.toCharArray();
        int count = 0;
        for (int i = 0,length = charsX.length; i < length; i++) {
            int result = charsX[i] ^ charsY[i];
            if (result == 1){
                count++;
            }
        }
        
        return count;
    }
```
