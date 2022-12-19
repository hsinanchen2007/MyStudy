<?php    

//参考了java的第一条热门答案，个人觉得这个答案很不错

function wordPattern($pattern, $str) {
    $sArr = explode(" ",$str);
    if (count($sArr) != strlen($pattern)) return false;
    $map =  [];  //哈希表

    for ($i = 0;$i < strlen($pattern);$i++){
        if (!isset($map[$pattern[$i]])){  //如果哈希表中没有pattern的映射
            if (in_array($sArr[$i],$map)) return false; //如果该s值已经在哈希表中了
            $map[$pattern[$i]] = $sArr[$i]; //添加映射
        }else{
            if ($map[$pattern[$i]] != $sArr[$i]) return false;  //如果哈希表中有映射但是与相应的s不等
        }
    }
    return true;
}