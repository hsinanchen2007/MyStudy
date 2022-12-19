```
object Solution {
    def longestPalindrome(s: String): String = {
        //遍历s，令s（i）为中心，向两边扩展，分奇数回文子串和偶数回文子串来做
        val indices = s.indices
        var res = ""
        println(indices)
        for(i <- indices) {
            var restmp = ""
            //奇数情况
            var res1 = ""
            var flag1 = true
            var left1 = i
            var right1 = i
            while(flag1) {
                flag1 = indices.contains(left1) && indices.contains(right1) && s(left1)==s(right1)
                if(flag1 == true) {
                    left1 = left1 - 1
                    right1 = right1 + 1
                }
            }
            var res11 = s.substring(left1+1,right1)
            if(res11.length()>res1.length())
                res1 = res11
            //偶数情况
            var res2 = ""
            var flag2 = true
            var left2 = i-1
            var right2 = i
            while(flag2) {
                flag2 = indices.contains(left2) && indices.contains(right2) && s(left2)==s(right2)
                if(flag2==true) {
                    left2 = left2 - 1
                    right2 = right2 + 1
                }
            }
            var res22 = s.substring(left2+1,right2)
            if(res22.length()>res2.length())
                res2 = res22
            if(res1.length()>res2.length) {
                restmp = res1
            }
            else {
                restmp = res2
            }
            if(restmp.length()>res.length())
                res = restmp
        }
        res
    }
}
```
