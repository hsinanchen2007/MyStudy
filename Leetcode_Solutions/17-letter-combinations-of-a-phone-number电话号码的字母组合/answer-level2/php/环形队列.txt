先说结果，执行用时0ms，在php中击败100%的用户；内存14.9M，击败了13.79%。

解法思路：
就是一个环形队列的感觉，左边进，右边出，循环一圈开始下一轮：
比如题目中给的‘23’：
第一次跑‘2’，队列变成【c,b,a】
然后跑‘3’，弹出队队尾的元素【a】，看这个元素的长度是不是等于2，如果不是，就分别把3对应的字母【d,e,f】分别和弹出的【a】拼起来，从队首插进去，这样再跑完一圈，队列变成了【cf,ce,cd,bf,be,bd,af,ae,ad】

如果输入的是‘234’，那下一轮就继续跑‘4’。弹出队尾的元素【ad】，看长度是否等于3，如果不是，就把4对应的【h,i,g】分别和弹出的【ad】，拼起来，从队首往回插。

依次类推。

function letterCombinations($digits) {
    $loopQueue = [];
    $mapping = [
        //1=>[],
        2=>['a','b','c'],
        3=>['d','e','f'],
        4=>['g','h','i'],
        5=>['j','k','l'],
        6=>['m','n','o'],
        7=>['p','q','r','s'],
        8=>['t','u','v'],
        9=>['w','x','y','z'],
    ];
    $strlen = strlen($digits);
    $contain = '';
    for($i = 0;$i<$strlen;$i++){
        do{
            $end = end($loopQueue);
            if(strlen($end) != $i+1){
                $contain = array_pop($loopQueue);
            }else{
                break;
            }
            foreach($mapping[$digits[$i]] as $v){
                $one = $contain.$v;
                array_unshift($loopQueue,$one);
            }
        }while(2>1);

    }
    return $loopQueue;
}