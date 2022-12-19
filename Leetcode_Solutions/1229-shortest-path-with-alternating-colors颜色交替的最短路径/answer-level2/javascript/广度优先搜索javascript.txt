广度优先遍历

```javascript []
/**
 * @param {number} n
 * @param {number[][]} red_edges
 * @param {number[][]} blue_edges
 * @return {number[]}
 */
var shortestAlternatingPaths = function(n, red_edges, blue_edges) {

	let result = Array(n).fill(-1)
	result[0] = 0

	let build = [
			[
				[0, 0, 's']
			]
		],
		floor = [],
		len = 0 // 楼层

	while (build[len].length > 0) {
		let last = build[len]

		for (let edge of last) {
			if (edge[2] == 'b') {
				for (let i = 0; i < red_edges.length; i++) {
					if (edge[1] == red_edges[i][0]) {
						red_edges[i].push('r')
						floor.push(red_edges[i])
						if (result[red_edges[i][1]] == -1) {
							result[red_edges[i][1]] = len + 1
						}
						red_edges.splice(i--, 1)
					}
				}
			} else if (edge[2] == 'r') {
				for (let i = 0; i < blue_edges.length; i++) {
					if (edge[1] == blue_edges[i][0]) {
						blue_edges[i].push('b')
						floor.push(blue_edges[i])
						if (result[blue_edges[i][1]] == -1) {
							result[blue_edges[i][1]] = len + 1
						}
						blue_edges.splice(i--, 1)
					}
				}
			} else if (edge[2] == 's') {
				for (let i = 0; i < red_edges.length; i++) {
					if (edge[1] == red_edges[i][0]) {
						red_edges[i].push('r')
						floor.push(red_edges[i])
						if (result[red_edges[i][1]] == -1) {
							result[red_edges[i][1]] = len + 1
						}
						red_edges.splice(i--, 1)
					}
				}
				for (let i = 0; i < blue_edges.length; i++) {
					if (edge[1] == blue_edges[i][0]) {
						blue_edges[i].push('b')
						floor.push(blue_edges[i])
						if (result[blue_edges[i][1]] == -1) {
							result[blue_edges[i][1]] = len + 1
						}
						blue_edges.splice(i--, 1)
					}
				}
			}
		}
		len++
		build.push(floor)
		floor = []
	}
	return result
};
```