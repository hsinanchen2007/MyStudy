/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/9/27
 *
 * 解题思路: 想添加一个数字必须是 1.开头两个0 [0,0,...] 2.结尾两个0 [...,0,0] 3. 中间三个0 [...,0,0,0,...]
 *
 *  注意:flowered[] 长度为1直接判断 为0直接返回true两个情况
 * 
 *  解题思路2:
 * 遍历flowerbed[]数组，依次判断各位置是否适合种花，判断的标准是当前位置为0，且前一位置为0或其下标为-1，且后一位置为0或其下标为flowerbed.length。若判断为真，则修改flowerbed[]数组当前位置为1，n--。最后若n<=0,则能种下所有花
 *
 *
 */

```

 public boolean canPlaceFlowers2(int[] flowerbed, int n) {
    for (int i = 0; i < flowerbed.length; i++) {
        if (flowerbed[i] == 0&& (i - 1 == -1 || flowerbed[i - 1] == 0) && (i + 1 == flowerbed.length || flowerbed[i + 1] == 0)) {
            n--;
            flowerbed[i] = 1;
            if(n <= 0) break;
        }
    }
    return n <= 0 ? true:false;
}

 public boolean canPlaceFlowers(int[] flowerbed, int n) {
    if(flowerbed.length == 1){
        if(n == 1 && flowerbed[0] == 1){
            return false;
        }else{
            //n == 0 && flowerbed[0] == 0 || n == 1 && flowerbed[0] == 0 || n == 0 && flowerbed[0] == 1
            return true;
        }
    }
    if(n == 0) return true;

    for(int i = 0;i < flowerbed.length - 1;){

        if(flowerbed[i] == 1) {
            i++;
            continue;
        }
        // == 0
        if(i == 0 && flowerbed[i + 1] == 0){
            flowerbed[i] = 1;
            n--;
            i+=1;
        }else if(i == flowerbed.length - 2 && flowerbed[i + 1] == 0){
            flowerbed[i + 1] = 1;
            n--;
            i+=1;
        }else if(flowerbed[i + 1] == 0 && flowerbed[i + 2] == 0){
            flowerbed[i + 1] = 1;
            n--;
            i+=1;
        }else{
            i++;
        }

        if(n <= 0) break;
    }
    return n <= 0?true:false;
}
```