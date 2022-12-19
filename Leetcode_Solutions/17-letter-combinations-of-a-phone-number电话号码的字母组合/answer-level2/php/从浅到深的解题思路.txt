## 1、假设题目是这样的
每个数字对应一个字母：`2->a,3->d,4->g,5->j...`，求输入不同数字，给出不同的字母组合。

这样的话就很简单了，假设输入数字23，我们很容易组合出字母ad；输入数字34，组合出dg...

因为 数字->字母 一一对应，我们仅使用遍历就能解决，但为了下面题目升级做准备，我们使用递归的思路解决，代码如下。

```
class Solution {

    /**
     * @param String $digits
     * @return String[]
     */
    function letterCombinations($digits) {
        //hash_table 获取下标对应的字母
        $map = ["","","a","d","g","j","m","p","t","w"];
        //特殊情况处理
        $result = [];
        if(empty($digits)) return $result;

        //有数字输入情况处理
        $this->helper($map,$digits,"",$result);
        return $result;
    }

    function helper($map,$next_digit,$combine,&$result)
    {
        //1、terminator，跳出条件，当递归到数字结束的时候跳出。
        if(empty($next_digit)){
            array_push($result,$combine);
            return ;
        }

        //2、process
        $pos = substr($next_digit,0,1);
        $pos_letter = $map[$pos];
        $next_digit = substr($next_digit,1);
        $this->helper($map,$next_digit,$combine.$pos_letter,$result);
    }
}
```

## 2、题目升级
假设，数字与字母不是一一对应，`2->abc,3->def,4->ghi,...`

那么我们改写下上面的代码即可：
```
class Solution {

    /**
     * @param String $digits
     * @return String[]
     */
    function letterCombinations($digits) {
        //hash_table 获取下标对应的字母
        $map = ["","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"];
        //特殊情况处理
        $result = [];
        if(empty($digits)) return $result;

        //有数字输入情况处理
        $this->helper($map,$digits,"",$result);
        return $result;
    }

    function helper($map,$next_digit,$combine,&$result)
    {
        //1、terminator，跳出条件，当递归到数字结束的时候跳出。
        if(empty($next_digit)){
            array_push($result,$combine);
            return ;
        }

        //2、process
        $pos = substr($next_digit,0,1);
        $pos_letter = $map[$pos];
        $next_digit = substr($next_digit,1);
        //因为不是一一对应，加入循环
        for($i=0;$i<strlen($pos_letter);$i++){
            $this->helper($map,$next_digit,$combine.$pos_letter[$i],$result);
        }
    }
}
```

递归太难了。。想了半天才想到这程度。加油兄弟们。