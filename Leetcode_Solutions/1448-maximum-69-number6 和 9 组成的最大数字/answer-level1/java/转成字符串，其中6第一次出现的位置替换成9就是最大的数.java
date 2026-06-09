```
class Solution {
    public int maximum69Number (int num) {
        //转成字符串
        String numStr = String.valueOf(num);
        //找出字符串中6第一次出现的位置
		int index = numStr.indexOf('6');
        //没有6返回原正整数
        if(index == -1){
            return num;
        }
        //把6的位置替换成9
        StringBuilder sbd = new StringBuilder(numStr);
        String res = sbd.replace(index,index+1,"9").toString();
        return Integer.parseInt(res);
    }
}
```
