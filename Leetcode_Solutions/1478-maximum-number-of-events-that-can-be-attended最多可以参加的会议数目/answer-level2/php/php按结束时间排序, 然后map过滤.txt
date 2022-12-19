思路：自己不会，参照别人的思路做的。
代码：
```php
class Solution {

    /**
     * @param Integer[][] $events
     * @return Integer
     */
    function maxEvents($events) {
        if(sizeof($events)==1)
            return 1;
        
        $a1=[];
        $a2=[];
        foreach ($events as $key => $row) {
            $a1[$key]  = $row[0];
            $a2[$key] = $row[1];
        }
        // 按照结束时间排序, 结束时间相同的开始时间早的在前
        array_multisort( $a2, SORT_ASC,$a1, SORT_ASC, $events);

        $len=sizeof($events);
        $ret=[];
        // 遍历
        for($i=0;$i<$len;$i++){
            // 如果当天没有参加过会议, 则添加该次会议的开始时间
            if(!isset($ret[$events[$i][0]])){
                $ret[$events[$i][0]]=true;
            }else{
                // 否则的话遍历结束时间范围
                $start=$events[$i][0];
                $end=$events[$i][1];
                while($end>$start){
                    $start++;                    
                    if(!isset($ret[$start])){// 如果在返回内有时间则参加会议, 并break
                        $ret[$start]=true;
                        break;
                    }
                }
            }
        }
        return sizeof($ret);
    }
}
```
