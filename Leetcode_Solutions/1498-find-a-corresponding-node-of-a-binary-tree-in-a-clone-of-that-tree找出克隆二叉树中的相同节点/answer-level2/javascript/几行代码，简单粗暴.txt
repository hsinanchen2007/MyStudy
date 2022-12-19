```
var getTargetCopy = function(original, cloned, target) {
	if (original === null) {
		return null
	}
  	if (original === target) {
  		return cloned
  	}
  	return getTargetCopy(original.left, cloned.left, target) || getTargetCopy(original.right, cloned.right, target)
};
```
