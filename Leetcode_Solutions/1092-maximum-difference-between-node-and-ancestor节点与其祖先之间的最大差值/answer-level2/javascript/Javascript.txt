

var maxAncestorDiff = function(root) {
    if( root == null)
    return 0;
    let min =root.val;
    let max =root.val;
    return Math.max(dfs(root.left, min, max), dfs(root.right, min, max));
};

function dfs(root,min,max){
        if (root == null)
			return max - min;
		if (root.val < min)
			min = root.val;
		if (root.val > max)
			max = root.val;
		return Math.max(dfs(root.left, min, max), dfs(root.right, min, max));
}
