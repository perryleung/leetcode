/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 *
 * https://leetcode-cn.com/problems/longest-common-subsequence/description/
 *
 * algorithms
 * Medium (60.50%)
 * Likes:    315
 * Dislikes: 0
 * Total Accepted:    60.3K
 * Total Submissions: 99.4K
 * Testcase Example:  '"abcde"\n"ace"'
 *
 * 给定两个字符串 text1 和 text2，返回这两个字符串的最长公共子序列的长度。
 * 
 * 一个字符串的 子序列 是指这样一个新的字符串：它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。
 * 例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde"
 * 的子序列。两个字符串的「公共子序列」是这两个字符串所共同拥有的子序列。
 * 
 * 若这两个字符串没有公共子序列，则返回 0。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入：text1 = "abcde", text2 = "ace" 
 * 输出：3  
 * 解释：最长公共子序列是 "ace"，它的长度为 3。
 * 
 * 
 * 示例 2:
 * 
 * 输入：text1 = "abc", text2 = "abc"
 * 输出：3
 * 解释：最长公共子序列是 "abc"，它的长度为 3。
 * 
 * 
 * 示例 3:
 * 
 * 输入：text1 = "abc", text2 = "def"
 * 输出：0
 * 解释：两个字符串没有公共子序列，返回 0。
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 <= text1.length <= 1000
 * 1 <= text2.length <= 1000
 * 输入的字符串只含有小写英文字符。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        return helper(text1, text2, text1.size() - 1, text2.size() - 1);
    }
    int helper(string& text1, string& text2, int len1, int len2) {
        if (len1 == -1 || len2 == -1)
            return 0;
        if (text1[len1] == text2[len2])
            return helper(text1, text2, len1 - 1, len2 - 1) + 1;
        else {
            return max(helper(text1, text2, len1, len2 - 1), helper(text1, text2, len1 - 1, len2));
        }
    }
};
// @lc code=end

