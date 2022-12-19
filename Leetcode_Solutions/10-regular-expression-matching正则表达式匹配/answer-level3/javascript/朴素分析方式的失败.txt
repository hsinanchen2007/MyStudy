我整整搞了好久，用最朴素思路去编排[两个指针从左到右去匹配，然后两个都遍历完就表示成功，搞着搞着越来越多情况，就各种场景处理]，分类各种情况，坑得一皮，测试用例走了一遍又一遍，发现场景越来越多，直到发现走进死胡同了。
比赛和面试这种方式最坑人了，但平时分析大部分都是朴素分析方式！
```
var isMatch = function (s, p) {
        let i = 0, j = 0;
        var flag = true
        while (i < s.length && j < p.length) {
            if (j + 1 < p.length) {//处理方式应该两个特殊字符
                let pe = p.substring(j, j + 2);
                if (pe == '.*') {
                    if (j + 2 < p.length) {
                        // if (i + 2 < s.length) {
                        //     i += 2
                        //     while (s[i] != p[j + 2]) {
                        //         i++
                        //     }
                        // } else {//s单个字符、两个字符都可匹配'.*'
                        //     return true
                        // }
                       i = s.indexOf(p[j+2])
                    } else {
                        return true//可匹配后面任何字符串
                    }
                } else if (pe[1] == '*') {//"aab", "c*a*b"   ("aa", "a*aa")
                    //*一定要先关注p后面的匹配串,后面还有这种情况，从左到右就解决不了
                    if (j+2<p.length) {
                        s.indexOf(p)
                    }
                    while (s[i] == p[j] && i < s.length) {//(,**)????
                        i++
                    }
                    if (i==s.length&&j+3==p.length&&p[j+2]==p[j]) {
                        return true
                    }
                }
                else if (pe[1] == '.') {
                    if (s[i] == p[j]) {
                        i += 2
                    } else {
                        return false
                    }
                } else {
                    if (s[i] == p[j]) {
                        i += 1
                        flag = false
                    } else {
                        return false
                    }
                }
            } else {//空的不可能,(1,2):(a,*a),(a,aa),(a,a*),(a,aa)|(1,1)|
                if (i + 1 < s.length) {//(2,1):(aa,a),(aa,*),(aa,.)
                    return false
                } else {
                    if (p[j] == '.') {//(1,1):(a,.),(a,*),(a,b)
                        return true
                    } else {
                        return p[j] == s[i] //isMatch("a","")
                    }
                }
            }
            if (flag) {
                j += 2
            } else {
                j++
                flag = true
            }
        }
        // ("aaa", "a*a")处理不掉
        return i == s.length && j == p.length
    };
```
