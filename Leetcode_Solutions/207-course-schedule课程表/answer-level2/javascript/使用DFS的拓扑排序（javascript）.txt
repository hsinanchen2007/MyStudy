```javascript
  class GraphByList {
      constructor(isDirected = false) {
        this.isDirected = isDirected;
        this.size = 0;
        this.vertices = [];     // 顶点数组
        this.adjacencyList = [];//放置邻居顶点组成的链表，以索引作为标记
      }
      locate(a) {
        return this.vertices.indexOf(a)
      }
      setEdge(a, b, weight) {
        this.insertEdge(a, b, weight);
        if (!this.isDirected) {
          this.insertEdge(b, a, weight);
        }
      }
      insertEdge(a, b, weight) {
        var pos = this.locate(b);
        if (pos === -1) {
          throw '请提前设置顶点数组'
        }
        var index = this.locate(a)
        var node = this.adjacencyList[index];
        var prev = {
          next: node,
          pos: -1
        }
        var head = prev, toInsert
        while (node) {
          if (node.name == b) { //已经设置过这边，返回
            return
          }
          if (node.pos > pos) {
            toInsert = prev;
            break
          }
          prev = node;
          node = prev.next;
        }
        if (!toInsert) { //就是最后一个prev
          toInsert = prev;
        }
        var inserted = {
          pos,
          name: b,
          weight: weight,
          next: null
        }
        var next = toInsert.next;
        toInsert.next = inserted;
        inserted.next = next;
        if (toInsert === head) {
          this.adjacencyList[index] = head.next;
        }
        this.size++;
      }
    }


    function dfsByTopo(graph, index, visied, cb, back) {
      visied[index] = 1//被访问过的结点置为1
      var list = graph.adjacencyList
      var p = list[index]
      while (p) {
        if (visied[p.pos] == 1) {
          return false
        }
        if (!visied[p.pos] && !dfsByTopo(graph, p.pos, visied, cb)) {
          return false
        }
        p = p.next;
      }
      visied[index] = -1
      cb(graph.vertices[index], index) //取顶点
      return true
    }
    GraphByList.prototype.topologicalSort = function () {
      var result = []
      var visited = [];
      for (var i = 0; i < this.vertices.length; i++) {
        if (!visited[i] && !dfsByTopo(this, i, visited, function (el) {
          result.push(el)
        })) {
          break
        }
      }
      return result.reverse()
    }
    var canFinish = function (numCourses, prerequisites) {
      var g = new GraphByList(true);
      var vertices = []
      for (var i = 0; i < numCourses; i++) {
        vertices.push(i)
      }
      g.vertices = vertices
      prerequisites.forEach(function (el) {
        g.setEdge(el[0], el[1])
      })
      var list = g.topologicalSort()
      
      return list.length === numCourses
    };
```