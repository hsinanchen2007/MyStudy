Kahn算法
```
function findOrder($numCourses, $prerequisites) {
    $adj = array_fill(0,$numCourses,[]); // 邻接关系表
    $inDegree = array_fill(0,$numCourses,0); // 统计每个顶点的引入次数
    foreach($prerequisites as $p){
        $adj[$p[1]][] = $p[0]; // 存入每个点的可达节点集合
        $inDegree[$p[0]]++;
    }
    $queue = []; // 创建一个队列
    for($i=0;$i<$numCourses;$i++){// 加入引入次数为0的结点
        if($inDegree[$i]==0) array_push($queue,$i);
    }
    $ans = [];
    while(!empty($queue)){
        $num = array_pop($queue);
        $ans[] = $num;// 把引入次数为0的节点，存入结果序列
        foreach($adj[$num] as $node){// 遍历$num的可达节点
            $inDegree[$node]--; // 把这个$num节点的可达节点$node的引入次数减一
            if($inDegree[$node] == 0) array_push($queue,$node);
        }
    }
    return count($ans)==$numCourses?$ans:[];
}
```


建立逆邻接关系表，进行深度优先遍历
```
class Solution {

    /**
     * @param Integer $numCourses
     * @param Integer[][] $prerequisites
     * @return Integer[]
     */
    function findOrder($numCourses, $prerequisites) {
        $iadj = array_fill(0,$numCourses,[]); // 逆邻接关系表
        foreach($prerequisites as $p){
            $iadj[$p[0]][] = $p[1]; // 记录每个点的逆可达节点集合
        }
        $visited = array_fill(0,$numCourses,0); // 创建访问记录数组,0代表未访问，1代表正在被当前dfs占用，2代表已访问未占用
        $ans = [];
        for($i=0;$i<$numCourses;$i++){
            if(!$this->dfs($i,$iadj,$visited,$ans)) return []; // 说明存在环，课程任务不能完成。
        }
        return $ans;
    }

    function dfs($i,$iadj,&$visited,&$ans){
        if($visited[$i]==1) return false; // 1代表正在被当前dfs占用，说明遇到了环。
        if($visited[$i]==2) return true; // 2代表已访问未占用
        $visited[$i] = 1; // 开始占用访问资源
        foreach($iadj[$i] as $node){
            if(!$this->dfs($node,$iadj,$visited,$ans)){
                array_pop($ans);
                return false;
            }
        }
        $visited[$i] = 2; // 解除占用，标记为已访问未占用
        $ans[] = $i;
        return true;
    }
}
```
