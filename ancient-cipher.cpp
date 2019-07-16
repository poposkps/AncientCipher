
std::multiset<size_t> calculate_pattern_of_ancient_cipher(const std::string & str)
{
    typedef size_t char_count_t;
    typedef std::map<char, char_count_t> char_counting_mapping_t;
    char_counting_mapping_t char_counting;
    for (auto character : str)
    {
        auto iter = char_counting.find(character);
        if (iter == char_counting.end())
        {
            char_counting[character] = 1;
        }
        else
        {
            iter->second++;
        }
    }


    std::multiset<size_t> result;
    for (const auto & items : char_counting)
    {
        result.insert(items.second);
    }
    return result;
}

bool compare_ancient_cipher(const std::string & input1, const std::string & input2)
{
    if (input1.size() != input2.size())
    {
        return false;
    }
    else
    {
        return calculate_pattern_of_ancient_cipher(input1) == calculate_pattern_of_ancient_cipher(input2);
    }
}

int main()
{
#if 0
    BOOST_ASSERT(true == compare_ancient_cipher("JWPUDJSTVP", "VICTORIOUS"));
    BOOST_ASSERT(false == compare_ancient_cipher("MAMA", "ROME"));
    BOOST_ASSERT(true == compare_ancient_cipher("HAHA", "HEHE"));
    BOOST_ASSERT(true == compare_ancient_cipher("AAA", "AAA"));
    BOOST_ASSERT(false == compare_ancient_cipher("NEERCISTHEBEST", "SECRETMESSAGES"));
#else
    std::string input1, input2;

    while (std::cin >> input1 >> input2)
    {
        std::cout << (compare_ancient_cipher(input1, input2) ? "YES" : "NO") << std::endl;
    }
    return 0;
#endif
}
