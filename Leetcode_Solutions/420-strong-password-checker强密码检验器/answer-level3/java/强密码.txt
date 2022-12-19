


```
import java.util.*;
class Solution {
    //连续字符的长度不能大于等于3
    private final int NOT_FREQ =  3;
    //字符串的最小长度
    private final int SHORT_LENGTH = 6;
    //字符串的最大长度
    private final int LONG_LENGTH = 20;
    public int strongPasswordChecker(String s) {
        //reuslt为需要返回的结果值
        int result = 0;
        //统计大写字母的数量
        int upNum = 0;
        //统计小写字母的数量
        int lowerNum = 0;
        //统计数字的数量
        int digitNum = 0;
        //数组中的每个元素是一堆连续字符的出现次数（不小于三）
        List<Integer> seqNum = new ArrayList<>();

        //获得所需变量的值
        int num = 0;
        for(int i = 0; i < s.length(); i++) {
            if(i == 0) {
                num = 1;
            }else {
                if(s.charAt(i) == s.charAt(i - 1)) {
                    num++;
                }else {
                    if(num >= NOT_FREQ) {
                        seqNum.add(num);
                        num = 1;
                    }else
                        num = 1;
                }
            }
            if(s.charAt(i) >= 'a' && s.charAt(i) <= 'z') {
                lowerNum++;
            }else if(s.charAt(i) >= 'A' && s.charAt(i) <= 'Z') {
                upNum++;
            }else if(s.charAt(i) >= '0' && s.charAt(i) <= '9') {
                digitNum++;
            }
        }
        if(num >= NOT_FREQ) {
            seqNum.add(num);
        }

        if(s.length() < SHORT_LENGTH) {
            result = shortSolve(upNum, lowerNum, digitNum, s, seqNum);
        }

        if(s.length() > LONG_LENGTH) {
            result = longSolve(upNum, lowerNum, digitNum, s, seqNum);
        }

        if(s.length() >= SHORT_LENGTH && s.length() <= LONG_LENGTH) {
            result = midSolve(upNum, lowerNum, digitNum, s, seqNum);
        }
        return result;
    }

    //当字符串的长度小于6，考虑增加和修改；增加或修改以使得up、lower、digit满足条件；必须增加使得长度变为1，而这必能使得不连续条件满足；
    //取两者较大值
    private int shortSolve(int upNum, int lowerNum, int digitNum, String s, List<Integer> seqNum) {
        int result;
        int a = 0;
        int b = 0;
        if(upNum == 0) {
            a++;
        }
        if(lowerNum == 0) {
            a++;
        }
        if(digitNum == 0) {
            a++;
        }
        b = SHORT_LENGTH - s.length();
        result = Math.max(a, b);
        return result;
    }
    //分级删除
    private int deletByKind(int limit, List<Integer> seqNum, int kind) {
        to:
        for (int i = 0; i < seqNum.size(); i++) {
            if (seqNum.get(i) % NOT_FREQ == kind) {
                for(int j = 0; j <= kind; j++) {
                    limit -= 1;
                    seqNum.set(i, seqNum.get(i) - 1);
                    if (limit == 0)
                        break to;
                }
            }
        }
        for (int i = seqNum.size() - 1; i >= 0; i--) {
            if (seqNum.get(i) < NOT_FREQ)
                seqNum.remove(i);
        }
        return limit;
    }

    /*长度过长必须删除，因为删除不增加字符种类，所以删除的尽量少，并且尽量减少之后对于不连续条件的修改;

    对于删除，删除连续出现字符中的字符，优先级为%3==0 删除1，%3==1 删除2，%3==2，删除3；
    因为（对于0-2连续，需要修改0；对于3-5连续，需要修改1......）直至字符串的长度等于20；

    之后进行》=6《=20的情况进行考虑*/
    private int longSolve(int upNum, int lowerNum, int digitNum, String s, List<Integer> seqNum) {
        //必须进行的删除操作，也是删除的额度
        int limit = s.length() - LONG_LENGTH;
        //因为该操作必须进行，对result进行操作
        int result = s.length() - LONG_LENGTH;
        //解决连续问题需要删除多少字符
        int need = 0;
        for (int fre : seqNum) {
            need += fre - NOT_FREQ + 1;
        }
        //若是在删除的额度内，则使用删除的额度解决长度问题跟连续问题
        //若删除的额度不能解决连续问题，那么在额度内尽量解决连续问题按照之前说的分级
        if (need <= limit) seqNum.clear();
        else {
            to:
            while (limit > 0) {
                //进行分级删除
                for(int i = 0; i < NOT_FREQ; i++) {
                    limit = deletByKind(limit, seqNum, i);
                    if(limit == 0)
                        break to;
                }
            }
        }
        result += midSolve(upNum, lowerNum, digitNum, s, seqNum);
        return result;
    }

    /*因为长度是满足条件的，所以要使得 digit、up、lower、不连续条件满足；解决前三者，修改、增加操作效果等同；
      解决最后一项，删除、增加效果不如修改；修改不影响长度；因此考虑修改；
      解决前三者和解决最后一项可以一起操作，所以取得解决前三者最少步数和解决最后一项最少步数之间的最大值
     */
    private int midSolve(int upNum, int lowerNum, int digitNum, String s, List<Integer> seqNum) {
        int result = 0;
        int a = 0;
        int b = 0;
        if (upNum == 0) {
            a++;
        }
        if (lowerNum == 0) {
            a++;
        }
        if (digitNum == 0) {
            a++;
        }

        for (int fre : seqNum) {
            b += fre / NOT_FREQ;
        }
        result += Math.max(a, b);
        return result;
    }
}
```

