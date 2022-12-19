<?php

    $strIn      ='1->2->3->3->4->4->5';
    $strArr     =explode('->',$strIn);
    $strRes     =unique_arr($strArr);
    var_dump(rtrim($strRes,'->'));
    function unique_arr(&$strArr){
        $strArr[]='n';
        $lon=count($strArr);
        if($lon==0) return false;
        $i=0;$j=1;$k=0;
        $firstStr=$strArr[0];
        $res='';
        for(;$j<$lon;$j++){
            if($strArr[$j]!=$firstStr){
                $i++;
                if($k==0){
                    $strArr[$i]=  $strArr[$j];
                    $res.=$firstStr.'->';
                    $firstStr=$strArr[$j];
                }else{
                    $k=0;
                    $firstStr=$strArr[$j];
                }
            }else{
                $k=1;
            }
        }
        return $res;
    }
?>    