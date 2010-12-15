/****************************************************************************
**
** Copyright (c) 2009-2010, Jaco Naude
**
** This file is part of Qtilities which is released under the following
** licensing options.
**
** Option 1: Open Source
** Under this license Qtilities is free software: you can
** redistribute it and/or modify it under the terms of the GNU General
** Public License as published by the Free Software Foundation, either
** version 3 of the License, or (at your option) any later version.
**
** Qtilities is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with Qtilities. If not, see http://www.gnu.org/licenses/.
**
** Option 2: Commercial
** Alternatively, this library is also released under a commercial license
** that allows the development of closed source proprietary applications
** without restrictions on licensing. For more information on this option,
** please see the project website's licensing page:
** http://www.qtilities.org/licensing.html
**
** If you are unsure which license is appropriate for your use, please
** contact support@qtilities.org.
**
****************************************************************************/

#ifndef ABSTRACT_TREE_ITEM_H
#define ABSTRACT_TREE_ITEM_H

#include "QtilitiesCoreGui_global.h"

#include <QtilitiesCore>
using namespace QtilitiesCore;

#include <QIcon>
#include <QBrush>
#include <QSize>
#include <QFont>

using namespace Qtilities::Core::Interfaces;

namespace Qtilities {
    namespace CoreGui {
        using namespace Qtilities::Core;
        class TreeNode;

        /*!
        \struct AbstractTreeItemData
        \brief Structure used by AbstractTreeItem to store private data.
          */
        struct AbstractTreeItemData {
            AbstractTreeItemData() {}
        };

        /*!
          \class AbstractTreeItem
          \brief The AbstractTreeItem is an abstract base class which can be used to build tree items.

          <i>This class was added in %Qtilities v0.2.</i>
        */
        class QTILITIES_CORE_GUI_SHARED_EXPORT AbstractTreeItem : virtual public IObjectBase
        {

        public:
            AbstractTreeItem();
            virtual ~AbstractTreeItem();

            //! Function to get the name of this tree item.
            /*!
              \param parent The name of the parent node which provides the context in which we want to get the name.
              By default gets the objectName(). If a parent is specified which does not contain this item, QString() is returned.
              */
            QString getName(TreeNode* parent = 0) const;
            //! Function to set the name of this tree item.
            /*!
              \param parent The name of the parent node which provides the context in which we want to set the name.
              By default gets the objectName(). If a parent is specified which does not contain this item, QString() is returned.
              */
            void setName(const QString& new_name, TreeNode* parent = 0);

        protected:
            /*!
              This function will add a formatting node to \p object_node with the formatting information of this item.
              At present the following information is part of the formatting export:
              - Background Color (Only the color)
              - Foreground Color (Only the color)
              - Size Hint
              - Status Tip
              - Tool Tip
              - Font

              The following information is not part of the formatting export:
              - Alignment
              - Icon

              \note Category: The category is not part of the export. It is part of this item's item node.
              */
            IExportable::Result saveFormattingToXML(QDomDocument* doc, QDomElement* object_node) const;
            IExportable::Result loadFormattingFromXML(QDomDocument* doc, QDomElement* object_node);

        public:
            // -------------------------------
            // Getter & Setter functions for object role properties
            // -------------------------------

            //! Sets the category of the tree item in the specified tree node.
            /*!
              \returns True if the category was succesfully set. False otherwise. Note that false will be returned when the category is the same as the current
              category and therefore will not be changed.
              */
            virtual bool setCategory(const QtilitiesCategory& category, TreeNode* tree_node);
            //! Sets the category of the tree item in the context specified by the given observer ID.
            /*!
              \param observer_id The observer ID of the context for which the category must be set. When -1,
              the function will assume that the item only has 1 parent and it will check if it has only one
              parent and if so, set the category for that parent. If it has more than one parent, the function
              will print an error message in release mode and assert id debug mode.

              \returns True if the category was succesfully set. False otherwise. Note that false will be returned when the category is the same as the current
              category and therefore will not be changed.

              \note If this tree item is not attached to any tree node, this function does nothing and
              returns false.
              */
            virtual bool setCategory(const QtilitiesCategory& category, int observer_id = -1);
            //! Gets the category of the tree item in the specified tree node.
            /*!
              \param tree_node The node context for which the category must be obtained for.

              \note If this tree item is not attached to any tree node, this function does nothing and
              returns false.
              */
            virtual QtilitiesCategory getCategory(TreeNode* tree_node) const;
            //! Gets the category of the tree item in the context specified by the given observer ID.
            /*!
              \param observer_id The observer ID of the context for which the category must be obtained for. When -1,
              the function will assume that the item only has 1 parent and it will check if it has only one
              parent and if so, return the category for that parent. If it has more than one parent, the function
              will print an error message in release mode and assert id debug mode.


              \note If this tree item is not attached to any tree node, this function does nothing and
              returns an empty category.
              */
            virtual QtilitiesCategory getCategory(int observer_id = -1) const;
            //! Gets the category in a string format where different hierarchies of the category is split using \p sep.
            /*!
              \note If this tree item is not attached to any tree node, this function does nothing and
              return false.
              */
            virtual QString getCategoryString(const QString& sep = "::") const;
            //! Sets the category in a string format where different hierarchies of the category is split using \p sep.
            /*!
              \note If this tree item is not attached to any tree node, this function does nothing and
              return false.
              */
            virtual bool setCategoryString(const QString& category_string, const QString& sep = "::");
            //! Checks if the item has a category.
            virtual bool hasCategory() const;
            //! Sets the tool tip of the tree item.
            void setToolTip(const QString& tooltip);
            //! Gets the tool tip of the tree item.
            QString getToolTip() const;
            //! Checks if the item has a tool tip.
            bool hasToolTip() const;
            //! Sets the icon of the tree item.
            void setIcon(const QIcon& icon);
            //! Gets the icon of the tree item.
            QIcon getIcon() const;
            //! Checks if the item has an icon.
            bool hasIcon() const;
            //! Sets the what's this text of the tree item.
            void setWhatsThis(const QString& whats_this);
            //! Gets the what's this text of the tree item.
            QString getWhatsThis() const;
            //! Checks if the item has what's this text.
            bool hasWhatsThis() const;
            //! Sets the status tip of the tree item.
            void setStatusTip(const QString& status_tip);
            //! Gets the status tip of the tree item.
            QString getStatusTip() const;
            //! Checks if the item has status tip text.
            bool hasStatusTip() const;
            //! Sets the size hint of the tree item.
            void setSizeHint(const QSize& size);
            //! Gets the size hint of the tree item.
            QSize getSizeHint() const;
            //! Checks if the item has a size hint.
            bool hasSizeHint() const;
            //! Sets the font of the tree item.
            void setFont(const QFont& font);
            //! Gets the font of the tree item.
            QFont getFont() const;
            //! Checks if the item has a font.
            bool hasFont() const;
            //! Sets the alignment of the tree item.
            void setAlignment(const Qt::AlignmentFlag& alignment);
            //! Gets the alignement of the tree item.
            Qt::AlignmentFlag getAlignment() const;
            //! Checks if the item has a font.
            bool hasAlignment() const;
            //! Sets the foreground role of the tree item.
            void setForegroundRole(const QBrush& foreground_role);
            //! Gets the foreground role of the tree item.
            QBrush getForegroundRole() const;
            //! Checks if the item has a foreground role.
            bool hasForegroundRole() const;
            //! Sets the foreground color of the tree item.
            /*!
              \note If this function is called after setForegroundRole(), the color of the brush set with that function will be changed.
              */
            void setForegroundColor(const QColor& color);
            //! Gets the foreground color of the tree item.
            /*!
              \return The foreground color if it has been set, QColor() otherwise.
              */
            QColor getForegroundColor() const;
            //! Sets the background role of the tree item.
            void setBackgroundRole(const QBrush& background_role);
            //! Gets the background role of the tree item.
            QBrush getBackgroundRole() const;
            //! Checks if the item has a background role.
            bool hasBackgroundRole() const;
            //! Sets the background color of the tree item.
            /*!
              \note If this function is called after setBackgroundRole(), the color of the brush set with that function will be changed.
              */
            void setBackgroundColor(const QColor& color);
            //! Gets the background color of the tree item.
            /*!
              \return The background color if it has been set, QColor() otherwise.
              */
            QColor getBackgroundColor() const;

        protected:
            AbstractTreeItemData* baseItemData;
        };
    }
}

#endif //  ABSTRACT_TREE_ITEM_H
