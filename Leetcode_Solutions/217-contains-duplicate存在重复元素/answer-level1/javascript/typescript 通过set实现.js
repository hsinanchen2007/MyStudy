通过set的唯一特性实现
```typescript
export function isDuplicate3(nums: Array<number>): boolean {
  const set = new Set(nums);
  return !(set.size === nums.length);
}
```