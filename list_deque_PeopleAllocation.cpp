#include <iostream>
#include <list>
#include <deque>

// Function to calculate the total number of people in all queues
int getTotalPeople(const std::list<std::deque<int>> &queues)
{
    int total = 0;
    for (const auto &queue : queues)
    {
        total += queue.size();
    }
    return total;
}

int main()
{
    // Initialize the list of queues
    std::list<std::deque<int>> queues;

    // Insert 5 empty queues into the list
    for (int i = 0; i < 5; ++i)
    {
        queues.push_back(std::deque<int>());
    }

    // Access each queue in the list and insert some random people into them with different numbers
    int personNumber = 1;
    for (auto &queue : queues)
    {
        for (int i = 0; i < 5; ++i)
        {
            queue.push_back(personNumber);
            ++personNumber;
            // Break the loop using random number generator
            if (rand() % 2 == 0)
            {
                break;
            }
        }
    }
    char choice;
    do
    {
        // Display the current state of queues
        int queueIndex = 1;
        for (const auto &queue : queues)
        {
            std::cout << "Queue " << queueIndex << ": ";
            for (int person : queue)
            {
                std::cout << person << " ";
            }
            std::cout << std::endl;
            ++queueIndex;
        }

        // Calculate the total number of people
        int totalPeople = getTotalPeople(queues);
        std::cout << "Total people in all queues: " << totalPeople << std::endl;

        // Insert new person into the queue with the fewest people
        int newPerson;
        std::cout << "Enter the number of the new person: ";
        std::cin >> newPerson;

        // Find the queue with the fewest people
        auto minQueue = queues.begin();
        int minSize = (*minQueue).size();
        for (auto it = queues.begin(); it != queues.end(); ++it)
        {
            if ((*it).size() < minSize)
            {
                minQueue = it;
                minSize = (*it).size();
            }
        }

        // Insert the new person into the queue with the fewest people
        (*minQueue).push_back(newPerson);

        // Randomly remove a person from a random queue
        int randomQueueIndex = rand() % queues.size();
        auto it = queues.begin();
        std::advance(it, randomQueueIndex);
        if (!(*it).empty())
        {
            (*it).pop_front();
        }

        // Ask if the user wants to insert more people
        std::cout << "Do you want to insert another person? (y/n): ";
        std::cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}
