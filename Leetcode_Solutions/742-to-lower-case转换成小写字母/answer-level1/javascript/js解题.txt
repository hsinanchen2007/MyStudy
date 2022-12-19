eg：'vjosjGER%R^GUIGIU'
typeof item判断结果是个string，也是本菜嘞。。。
`var toLowerCase = function(str) {
    let arr = str.split('')
	let array = arr.map((item) => {
		item = (/^[A-Za-z]+$/).test(item) ? item.charCodeAt() <= 90 ? item.charCodeAt() + 32 : item.charCodeAt() : item
		item = typeof item === 'number' ? String.fromCharCode(item) : item
		return item
	})
	return array.join('')
};
`