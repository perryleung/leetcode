/*
 * @lc app=leetcode.cn id=398 lang=cpp
 *
 * [398] 随机数索引
 *
 * https://leetcode-cn.com/problems/random-pick-index/description/
 *
 * algorithms
 * Medium (63.10%)
 * Likes:    85
 * Dislikes: 0
 * Total Accepted:    9.4K
 * Total Submissions: 14.8K
 * Testcase Example:  '["Solution","pick"]\n[[[1,2,3,3,3]],[3]]'
 *
 * 给定一个可能含有重复元素的整数数组，要求随机输出给定的数字的索引。 您可以假设给定的数字一定存在于数组中。
 * 
 * 注意：
 * 数组大小可能非常大。 使用太多额外空间的解决方案将不会通过测试。
 * 
 * 示例:
 * 
 * 
 * int[] nums = new int[] {1,2,3,3,3};
 * Solution solution = new Solution(nums);
 * 
 * // pick(3) 应该返回索引 2,3 或者 4。每个索引的返回概率应该相等。
 * solution.pick(3);
 * 
 * // pick(1) 应该返回 0。因为只有nums[0]等于1。
 * solution.pick(1);
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> nums;
    Solution(vector<int>& nums) {
        this->nums = nums;
    }
    
    int pick(int target) {
        int cnt = 1;
        int flag = 0;
        int index = -1;
        int res = index;
        for(int n : nums) {
            ++index;
            if(flag == 0) {
                if(n == target) {
                    flag = 1;
                    res = index;
                }
                continue;
            }
            if(n == target) {
                cnt++;
                if(rand() % cnt == 0)
                    res = index ;
            }
        }
        return res;
    }
        /* int cnt = 1;
        int flag = 1;
        int res;
        int index = -1;
        for(int c : nums){
            ++index;
            if(flag == 1) {
                if(c == target) {
                    res = index;
                    flag = 0;                   
                }
                continue;
            }  
            if(c == target) {
                cnt++;
                if (rand() % cnt == 0)
                    res = index;
            }
        }
        return res;
    } */
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
// @lc code=end

