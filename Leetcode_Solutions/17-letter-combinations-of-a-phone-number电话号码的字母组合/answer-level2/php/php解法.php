![image.png](https://pic.leetcode-cn.com/327a5d04a8f6dd4a7a80ce33f1dbbb3992cdbe552271e92d379f68192caf71e2-image.png)
基本思路就是排列组合吧，用php写出了大概，但是感觉在循环的时候出现了点问题，最后出来的组合会有问题(比如‘234’的时候会把23、24的组合也列出来)，所以最后加上了一个长度的判断来重新整合,等有空了想想是哪里出了问题然后再优化一下，内存消耗也需要优化一下

```
$number = array(
            1=>null,
            2=>array('a','b','c'),
            3=>array('d','e','f'),
            4=>array('g','h','i'),
            5=>array('j','k','l'),
            6=>array('m','n','o'),
            7=>array('p','q','r','s'),
            8=>array('t','u','v'),
            9=>array('w','x','y','z'),
        );
        $res = [];
        if($digits === "") return $res;

        $length = strlen($digits);
        if ($length < 1) return '';
        if ($length === 1) return $number[$digits];
        $result = [];
        $first = $number[$digits[0]]; //第一组的字母组
        $res = (substr($digits,1)); //剩下的数字
        for ($j = 0; $j < $length; $j ++) {
            $parr = $number[$res[0]]; //剩下数字的第一组
            for ($i = 0; $i < count($first); $i ++) {
                for ($e = 0; $e < count($parr); $e ++) {
                    $result[] = $first[$i].$parr[$e];
                }
            }
            if(strlen($res)==1){
               break;
            }
            $res = (substr($res,1));
            $first = $result;
        }
        foreach ($result as $key => $value) {
            if (strlen($value) < $length) {
                unset($result[$key]);
            }
        }
        $result = array_values($result);
        return $result;
```
