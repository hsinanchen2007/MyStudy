## Best Conceivable Solution

The best conceivable solution is the best you could conceive or come up with and there is no way to outperform this solution.

##### Time complexity
`O(n)`, where `n` is number of nodes in the tree.
Since each node needs to be checked at least once to get the result.

##### Space complexity

`O(1)`.
Since ideally we only need to cache the current root node.

## A sub-optimal solution

The following solution passes all 93 test cases of LeetCode 124, with a 100 ms runtime and 23 MB memory cost. It is sub-optimal compared to our best conceivable.

```swift
/// A binary tree node.
public class TreeNode {
  public var val: Int
  public var left: TreeNode?
  public var right: TreeNode?

  public init(_ val: Int) {
    self.val = val
    self.left = nil
    self.right = nil
  }
}

class Solution {
  /// Answer
  var a: Int = Int.min

  /// Finds the max sided path sum whose path `includes` given root node,
  /// and in the meanwhile, record the maximum path sum seen.
  /// - Definitions:
  ///   A sided path given root node chooses at most one child.
  /// - Note:
  ///   The `msl + v + msr` is recorded but not passed as return value.
  func maxSided(_ root: TreeNode?) -> Int {
    // Boundary condition: empty
    guard let r = root else { return 0 }

    let v = r.val
    let msl = maxSided(r.left)
    let msr = maxSided(r.right)

    a = max(a,       v      )
    a = max(a, msl + v      )
    a = max(a,       v + msr)
    a = max(a, msl + v + msr)

    return bigger(v, max(msl, msr) + v)
  }

  /// Finds the maximum path sum of a binary tree.
  /// - Source:
  ///   LeetCode 124 - Binary Tree Maximum Path Sum
  ///   Given a non-empty binary tree, find the maximum path sum.
  ///   For this problem, a path is defined as any sequence of nodes from some
  ///   starting node to any node in the tree along the parent-child connections.
  ///   The path must contain at least one node and does not need to go through
  ///   the root.
  /// - Definitions:
  ///     - Each `node` has an integer (negative or positive) `value`.
  ///     - A `path` is a set of nodes (one or more) and edges (zero or more)
  ///       that makes a single non-branching line,
  ///       where a node is connected to at most two of its neighboring edges.
  ///     - A `path sum` is a sum of values of all nodes in the path added up.
  /// - Assumptions:
  ///     - An empty tree has max path sum of zero.
  ///     - The sum of any number of nodes of the given binary tree does not
  ///       exceed the upper or lower bound of type Swift.Int64.
  ///     - The height of the binary tree is not given.
  /// - Best conceivable solution:
  ///     - Time complexity: O(n), where n is number of nodes in the tree.
  ///       Since each node needs to be checked at least once to get the result.
  ///     - Space complexity: O(1).
  ///       Since ideally we only need to cache the current root node.
  /// - Parameters:
  ///     - root: The given binary tree root node.
  /// - Returns: An integer as the value of the maximum path sum.
  /// - Submission:
  ///     - Time: 104 ms, faster than 44.30% of Swift submissions.
  ///     - Space: 23.2 MB, less than 100.00% of Swift submissions.
  func maxPathSum(_ root: TreeNode?) -> Int {
    guard let r = root else { return a }
    maxSided(r)
    return a
  }
}
```
