1. 构建链式前向星结构，同时存储每个顶点的出度（用数组保存，下标即为对应的顶点），注意无向图的边数是有向时的两倍
2. 遍历出度数组，生成一个由出度为1的顶点组成的数组（保存顶点的index）
3. 遍历出度为1的顶点数组，使用链式前向星找到对应的点所在的边
4. 找到对应的边后，进行删边操作
5. 因为是无向图，需要删除顶点相反时的另一条边，删除后判断顶点是否出度为1
- 5.1 出度为1则加入出度为1的数组；
- 5.2 出度不为1则忽略 
6. 循环直到边剩余数大于2，因为最后的情况只有可能是有两个顶点（对应两条边）或者一个顶点（无边）
7. 最后出度为1的数组中的数就是最小高度数的节点


```javascript
/**
 * @param {number} n
 * @param {number[][]} edges
 * @return {number[]}
 */
var findMinHeightTrees = function(n, edges) {
    const edgeListLen = edges.length;
    /** 边界情况 */
    if (edgeListLen * 2 === 2) {
        return edges[0].sort();
    }
    if (edgeListLen * 2 === 0) {
        return [0];
    }
    initHead(n);
    initOutList(n);

    /** 出度为1的顶点 数组 */
    const outOneList = [];

    /** 构造链式前向星 */
    for (let i = 0; i < edgeListLen; i++) {
        const cur = edges[i];
        addEdges(cur[0], cur[1]);
    }
    /** 筛选出度为1的顶点 */
    for (let i = 0; i < outList.length; i++) {
        if (outList[i] === 1) {
          outOneList.push(i);
        }
    }
    
    let elen = edgeListLen * 2;

    /** 最后只会有2两条边或者没有 */
    while (elen > 2) {
        let oneLen = outOneList.length;
        elen -= oneLen * 2;

        while (oneLen-- > 0) {
            const outOne = outOneList.shift();

            let edgeS = head[outOne];
            let targetS = edgeLinks[edgeS];

            if (targetS) {
                let edgeE = head[targetS.to];
                let targetE = edgeLinks[edgeE];

                /** 记录当前边和前一条边 */
                let edgeECurr = edgeE;
                let edgeEPrev = edgeE;

                while (targetE) {
                    if (targetE.to === outOne) {
                    /** 判断是否为第一个匹配到的边 */
                        if (edgeE === edgeECurr) {
                            if (targetE.next !== -1) {
                                /** 同一条边的next存在时，把next指向下一条边 */
                                head[targetS.to] = targetE.next;
                                /** 下一条边的next为-1， 说明下一条是最后一条，出度只剩下1 */
                                if (edgeLinks[targetE.next].next === -1) {
                                    /** 加入到出度为1的列表 */
                                    outOneList.push(targetS.to);
                                }
                            }
                            /** 删边 */
                            delete edgeLinks[edgeE];
                        } else {
                            /** 把前一条边的next指向当前边的next */
                            edgeLinks[edgeEPrev].next = edgeLinks[edgeECurr].next;
                            /** 下一条边的next为-1， 说明下一条是最后一条，出度只剩下1 */
                            if (edgeEPrev === edgeE && edgeLinks[edgeEPrev].next === -1) {
                                /** 加入到出度为1的列表 */
                                outOneList.push(targetS.to);
                            }
                            /** 删边 */
                            delete edgeLinks[edgeECurr];
                        }
                        delete edgeLinks[edgeS];
                        targetE = undefined;
                    } else {
                        if (targetE.next !== -1) {
                            /** 更新边的位置 */
                            edgeEPrev = edgeECurr;
                            edgeECurr = targetE.next;
                            /** 指向next的位置 */
                            targetE = edgeLinks[targetE.next];
                        } else {
                            targetE = undefined;
                        }
                    }
                }
            }
        }
    }
    return outOneList.sort();
};

/** edges index */
let cnt = 0;

/** 顶点对应的最后一次输入的边的index */
let head = [];

/** 顶点的出度 数组 */
let outList = [];

/** 链式前向星结构*/
const edgeLinks = [];

/**
 *
 * 无向图：s既可以是起点也是终点，v既可以是终点也可以是起点。一条边要算作两条边
 * @param {*} s 有向图：起点；无向图：起点或终点
 * @param {*} v 有向图：终点；无向图：起点或终点
 */
function addEdges (s, v) {
    /** s为起点时 */
    edgeLinks[cnt] = {};
    edgeLinks[cnt].to = v;
    edgeLinks[cnt].next = head[s];
    head[s] = cnt;
    cnt += 1;
    outList[s] += 1;

    /** v为起点时 */
    edgeLinks[cnt] = {};
    edgeLinks[cnt].to = s;
    edgeLinks[cnt].next = head[v];
    head[v] = cnt;
    cnt++;
    outList[v] += 1;
}

function initHead (n) {
    head = new Array(n).fill(-1);
}

function initOutList (n) {
    outList = new Array(n).fill(0);
}
```