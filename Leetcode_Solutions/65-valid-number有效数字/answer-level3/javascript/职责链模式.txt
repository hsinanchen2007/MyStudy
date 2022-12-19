```
/**
 * @param {string} s
 * @return {boolean}
 */
var isNumber = process([
    emptyValidator,
    spaceTrimmer,
    signTrimmer,
    integerValidator,
    floatValidator,
    sienceFormatValidator,
    falseValidator,
])

function falseValidator() {
    return false
}

function isNotNumber(value) {
    return isNaN(value) || value === "" || value === " "
}

/**
 * @param {string} value
 * @param {function} next
 */
function emptyValidator(value, next) {
    return value.trim().length !== 0 ? next(value) : false
}

/**
 * @param {string} value
 * @param {function} next
 */
function headTailIntegerValidator(value, next) {
    if (isNotNumber(value[0]) || isNotNumber(value[value.length - 1])) {
        return false
    }

    return next(value)
}

/**
 * @param {string} value
 * @param {function} next
 */
function headTailSpaceValidator(value, next) {
    if (value.startsWith(" ") || value.endsWith(" ")) {
        return false
    }

    return next(value)
}

/**
 * @param {string} value
 * @param {function} next
 */
function spaceTrimmer(value, next) {
    return next(value.trim())
}

/**
 * @param {string} value
 * @param {function} next
 */
function signTrimmer(value, next) {
    if (value.startsWith("+") || value.startsWith("-")) {
        value = value.substring(1)
    }

    return next(value)
}

/**
 * @param {string} value
 * @param {function} next
 */
function integerValidator(value, next) {
    for (const char of value) {
        if (isNotNumber(char)) {
        return next(value)
        }
    }

    return true
}

/**
 * @param {string} value
 * @param {function} next
 */
function floatValidator(value, next) {
    const partFloatValidator = process([
        emptyValidator,
        headTailIntegerValidator,
        emptyValidator,
        integerValidator,
        falseValidator,
    ])
    const pos = value.indexOf(".")

    if (pos === -1) {
        return next(value)
    }

    const left = value.substring(0, pos)
    const right = value.substring(pos + 1)

    // 处理 .xxx 的情况
    if (left === "") {
        if (partFloatValidator(right)) {
            return true
        }

        return next(value)
    }

    // 处理 xxx. 的情况
    if (right === "") {
        if (partFloatValidator(left)) {
            return true
        }

        return next(value)
    }

    if (partFloatValidator(left) && partFloatValidator(right)) {
        return true
    }

    return next(value)
}

/**
 * @param {string} value
 * @param {function} next
 */
function sienceFormatValidator(value, next) {
    const leftpartSienceFormatValidator = process([
        emptyValidator,
        signTrimmer,
        headTailSpaceValidator,
        emptyValidator,
        integerValidator,
        floatValidator,
        falseValidator,
    ])

    const rightpartSienceFormatValidator = process([
        emptyValidator,
        signTrimmer,
        headTailSpaceValidator,
        emptyValidator,
        integerValidator,
        falseValidator,
    ])
    value = value.toLowerCase()

    const pos = value.indexOf("e")

    if (pos === -1) {
        return next(value)
    }

    const left = value.substring(0, pos)
    const right = value.substring(pos + 1)

    if (
        leftpartSienceFormatValidator(left) &&
        rightpartSienceFormatValidator(right)
    ) {
        return true
    }

    return next(value)
}

/**
 * @param {function[]} validators
 */
function process(validators) {
    return validators.reduceRight((next, validate) => (data) =>
        validate(data, next)
    )
}
```

具体思路：[关于用设计模式刷 LeetCode 这件事](https://juejin.im/post/5e8afbc4f265da47e22f1509)
