```
class SnakeGame {

    function __construct($width, $height, $food) {
        $this->W = $width;
        $this->H = $height;
        $this->food = $food;
        $this->score = 0;
        $this->body_que = [[0,0]]; // 蛇身所占地图点位置队列
        $this->body_set[0] = 1; // 蛇身所占地图点位置索引，用于判断蛇头是否与蛇身相撞
    }

    function move($direction) {
        if(!$this->oneStep($direction)) return -1;
        return $this->score;
    }

    function oneStep($d){
        $oldTail = reset($this->body_que);
        $oldHead = end($this->body_que);
        array_shift($this->body_que); // 弹出oldTail
        unset($this->body_set[$this->getMapIndex($oldTail[0],$oldTail[1])]); // 去除oldTail索引
        $x = $oldHead[0];
        $y = $oldHead[1];
        switch($d){
            case "U": $x--; break;
            case "L": $y--; break;
            case "R": $y++; break;
            case "D": $x++; break;
        }
        if(!$this->check($x,$y)) return false;
        if(!empty($this->food) && $x==$this->food[0][0] && $y == $this->food[0][1]){
            // 如果碰见食物，蛇不发生移动，只执行吃。也就是蛇尾不弹出，蛇头入队列加长，所以需要恢复刚刚弹出的蛇尾
            array_unshift($this->body_que,$oldTail);
            $this->body_set[$this->getMapIndex($oldTail[0],$oldTail[1])] = 1;
            $this->score ++;
            array_shift($this->food); // 该食物出队列消失
        }
        // 执行蛇头队列加长
        $this->body_que[] = [$x,$y];
        $this->body_set[$this->getMapIndex($x,$y)] = 1;
        return true;
    }

    function check($x,$y){
        if($x<0 || $y<0 || $x>=$this->H || $y>=$this->W){
            return false;
        }
        $index = $this->getMapIndex($x,$y);
        if(array_key_exists($index, $this->body_set)){
            var_dump($this->body_set);
            var_dump($this->body_que);
            return false; // 蛇头与蛇身相撞
        }
        return true;
    }

    function getMapIndex($x,$y){ //获取地图矩阵该点所在索引
        return $x*$this->W + $y;
    }
}
```
