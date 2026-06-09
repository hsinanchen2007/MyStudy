     
3ms，击败98.71%
思路大致就是按位累加计算，记录是否进位，不过通过判断不需要补全字符串，可能提前退出，减少一丢丢时间
写的比较乱，思路大概是用a表示长的字符串，转为字符数组，从低位开始做和运算，用isUp记录是否进一，直接在字符数组里进行运算，如果短字符串已经遍历完，则开始判断isUp，若不进位则直接退出，若进位则按同样规则继续遍历。
最后可能长度会超过a（长字符串），那么做一次字符串拼接就好，将‘1’放在最前面。

   int lenA = a.length(), lenB = b.length();
        if(lenA < lenB){
            String item = a;
            a = b;
            b = item;
        }
        char[] chars = a.toCharArray();
        lenA = chars.length;
        lenB = b.length();
        boolean isUp = false;
        int addResult = 0;
        for(int i = lenA-1; i>=0 ; i--){
            if(i-lenA+lenB < 0){
                if(!isUp){
                    break;
                }else {
                    addResult = chars[i]+'0'+'1';
                }
            }else {
                addResult = chars[i]+b.charAt(i-lenA+lenB)+ (isUp?'1':'0');
            }
            switch (addResult){
                case 144:
                    isUp = false;
                    break;
                case 145:
                    chars[i] = '1';
                    isUp = false;
                    break;
                case 146:
                    chars[i] = '0';
                    isUp = true;
                    break;
                case 147:
                    chars[i] = '1';
                    isUp = true;
                    break;
                    default:
            }
        }
        return isUp?"1"+new String(chars) : new String(chars);