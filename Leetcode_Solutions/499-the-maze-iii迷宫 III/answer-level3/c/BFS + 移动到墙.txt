 * Algorithm:
 *     bfs(s, t)
 *      while (!q.empty) {
 *          foeach dir {
 *             reach wall/target
 *             if target {
 *                 update path & dist
 *             }
 *             else if min(d) || (equal(d) && path < pre-path)
 *                 update path.
 *                 push(point)
 *          }
 *      }
 