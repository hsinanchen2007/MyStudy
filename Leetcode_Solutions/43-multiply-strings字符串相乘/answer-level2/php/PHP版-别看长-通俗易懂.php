# **大概思路实现流程：**
先反转数组，便于理解操作。
按位数相乘，将结果放置应该的位置。
处理进位问题。
再反转数组。

    class Solution {

        /**
        * @param String $num1
        * @param String $num2
        * @return String
        */
        function multiply($num1, $num2) {
            if($num1 === '0' || $num2 === '0') return '0';
            $num1 = $this->reverse($num1);                   //反转数组   
            $num2 = $this->reverse($num2);
            $result = $this->multiplyLargeNum($num1, $num2);//相乘
            $resultStr = implode("", $result);              //讲数组转为字符串
            return $this->reverse($resultStr);              //再反转数组输出
        }
        //反转数组
        function reverse($num){
            $i = 0;
            var_dump($num);
            $j = strlen($num) - 1;
            while($i < $j){
                $tmp = $num[$i];
                $num[$i] = $num[$j];
                $num[$j] = $tmp;
                $i++;
                $j--;
            } 
            return $num;         
        }
        //相乘
        function multiplyLargeNum($num1, $num2){
            $len_1 = strlen($num1);
            $len_2 = strlen($num2);
            $result = [];
            for($i = 0; $i < $len_1; $i++){
                for($j = 0; $j < $len_2; $j++){
                    if(isset($result[$i + $j])){
                        $result[$i + $j] += ($num1[$i] - '0') * ($num2[$j] - '0');  
                    }else{
                        $result[$i + $j] = ($num1[$i] - '0') * ($num2[$j] - '0');
                    }
                }
            }
            //处理进位问题
            for($k = 0; $k < $len_1 + $len_2 -1; $k++){
                if($result[$k] >= 10){            
                    $result[$k + 1] += intval($result[$k] / 10);  //取改进位数
                    $result[$k] %= 10;                            //保留个位
                }
            }
            return $result;
        }
    }