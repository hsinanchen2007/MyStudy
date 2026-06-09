### 解题思路
其实思路倒是不难，只是写起来比较麻烦，包括小组的拓扑排序和项目的拓扑排序两个部分

### 代码

```javascript
/**
 * @param {number} n
 * @param {number} m
 * @param {number[]} group
 * @param {number[][]} beforeItems
 * @return {number[]}
 */
var sortItems = function(n, m, group, beforeItems) {
    //graph数组保存组内关系的结构: 小组号: 项目号:[入度，出边到的顶点集合] 
    //由于不同小组间不能交叉完成 所以只保存小组内的项目关系,以节省空间和时间，少做无用功。
    //cross记录跨组的顺序: 项目号:[小组号，出边到的非同组点顶点集合]
    //cross_group_sort 保存小组顺序拓扑关系 result保存最终结果
    //例子 n=8 m=2 group=[-1,-1,1,0,0,1,0,-1] beforeItems=[[],[6],[5],[6],[2,3,6],[],[],[]]
    var graph = [], cross_group = {}, cross_group_sort = {};
    var cross = [], result = [];
    //三遍循环初始化保存图的结构
    for(var i = 0; i<group.length; i++){
        graph[group[i]] = {};
    }
    //[{},{},"-1":{}];
    for(var i = 0; i < n; i++){
        graph[group[i]][i] = [0, []];
        cross_group[i] = [group[i],[]];
    }
    for(var i = 0; i < n; i++){
        for(var j=0; j<beforeItems[i].length;j++){
            //只有同一组才记录入度和出度边
            if(group[i] == group[beforeItems[i][j]]){
                graph[group[i]][i][0]++;
                graph[group[i]][beforeItems[i][j]][1].push(i);
            }
            if(cross_group[beforeItems[i][j]][0] != cross_group[i][0]){
                cross_group[beforeItems[i][j]][1].push(i);
            }
        }
    }
    /*
    [ { '3': [ 1, [4] ], '4': [ 2, [] ], '6': [ 0, [3] ] },
    { '2': [ 1, [] ], '5': [ 0, [2] ] },
    '-1': { '0': [ 0, [] ], '1': [ 0, [] ], '7': [ 0, [] ] } ]

    { '0': [ -1, [] ], '1': [ -1, [] ], '2': [ 1, [ 4 ] ], '3': [ 0, [] ],
    '4': [ 0, [] ], '5': [ 1, [] ], '6': [ 0, [ 1 ] ], '7': [ -1, [] ] }
    */
    //初始化小组拓扑结构
    var number_id;
    for(var i = 0; i < group.length; i++){
        if(!(group[i] in cross_group_sort)){
            cross_group_sort[group[i]] = [0,[]];
        }
    }
    for(var i in cross_group){
        if(cross_group[i][1].length != 0){
            for(var j = 0; j < cross_group[i][1].length; j++){
                number_id = cross_group[cross_group[i][1][j]][0];
                cross_group_sort[cross_group[i][0]][1].push(number_id);
                cross_group_sort[number_id][0]++;
            }
        }
    }

    //小组关系的拓扑关系
    var group_sort = [], falg;
    while(true){
        falg = 1;
        for(var i in cross_group_sort){
            if(cross_group_sort[i][0] == 0){
                group_sort.push(i);
                for(var j=0; j<cross_group_sort[i][1].length;j++){
                    cross_group_sort[cross_group_sort[i][1][j]][0]--;
                }
                delete cross_group_sort[i];
                falg = 0;
            }
        }
        if(falg){
            break;
        }
    }
    //整体项目的拓扑排序，以小组号为关键遍历
    for(var i = 0; i < group_sort.length; i++){
        var temp = group_sort[i];
        while(true){
            falg = 1;
            for(var j in graph[temp]){
                if(graph[temp][j][0] == 0){
                    result.push(j);
                    for(var k = 0; k < graph[temp][j][1].length; k++){
                        graph[temp][graph[temp][j][1][k]][0]--;
                    }
                    delete graph[temp][j];
                    falg = 0;
                }
            }
            if(falg){
                break;
            }
        }
    }
    if(result.length == n){
        return result;
    }else{
        return [];
    }
};
```