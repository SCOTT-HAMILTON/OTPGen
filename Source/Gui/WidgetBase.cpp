#include "WidgetBase.hpp"
#include "GuiHelpers.hpp"

WidgetBase::WidgetBase(QWidget *parent)
    : QWidget(parent)
{
}

WidgetBase::~WidgetBase()
{
    _maxRestoreButton = nullptr;
}

void WidgetBase::setMaxRestoreButton(QPushButton *btn) const
{
    _maxRestoreButton = btn;
}

const QPushButton *WidgetBase::maxRestoreButton() const
{
    return _maxRestoreButton;
}

QPushButton *WidgetBase::maxRestoreButton()
{
    return _maxRestoreButton;
}

void WidgetBase::updateWindowControls()
{
    if (_maxRestoreButton)
    {
        if (isMaximized())
        {
            _maxRestoreButton->setIcon(GuiHelpers::i()->restore_icon());
        }
        else
        {
            _maxRestoreButton->setIcon(GuiHelpers::i()->maximize_icon());
        }
    }
}

void WidgetBase::closeEvent(QCloseEvent *event)
{
    emit closed();
    event->accept();
}

void WidgetBase::resizeEvent(QResizeEvent *event)
{
    emit resized();
    event->accept();
}
