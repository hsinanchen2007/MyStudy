1、将待拼凑字符串和给定字符串转换成char数组；

2、定义spellArr 为待拼凑字符串char数组，textArr为给定字符串char数组，num为最终拼凑字符串数量；

3、循环spellArr 数组每一个，通过遍历textArr数组，寻找是否有该spellArr 元素；

4、如有，则将textArr中该元素值置为'0'，且跳出对textArr数组的遍历， 进行spellArr数组下一元素匹配，直至spellArr数组中所有元素匹配完成，此时num+1；如无，则直接返回记录待拼凑字符串数量；

代码：
public int maxNumberOfBalloons(String text) {
        int num = 0;
        char [] spellArr = "balloon".toCharArray();
        char [] textArr = text.toCharArray();
        while(true) {
            for(int i=0;i<spellArr.length;i++) {
                for(int j=0;j<textArr.length;j++) {
                    if(spellArr[i] == textArr[j]) {
                        textArr[j] = '0';
                        break;
                    } else {
                        if(j == textArr.length-1) {
                            return num;
                        }
                    } 
                }  
                if(i == spellArr.length-1) {
                    num ++;
                }     
            }
        }
    }
}

